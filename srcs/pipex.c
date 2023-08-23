/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:07:21 by xeherzi           #+#    #+#             */
/*   Updated: 2023/08/23 13:13:46 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_and_execute(char **cmd, char **envp)
{
	char	**path;

	if (ft_strchr(*cmd, ' '))
		cmd = ft_split(*cmd, ' ');
	if (!cmd)
		exit_error("malloc fail\n", 12);
	if (access(*cmd, F_OK | X_OK) == 0)
	{
		execve(*cmd, cmd, envp);
		exit_error("execution fail\n", 127);
	}
	path = find_path(envp, *cmd);
	if (!path)
		exit_error("malloc fail\n", 12);
	while (path)
	{
		if (access(*path, F_OK | X_OK) == 0)
		{
			execve(*path, cmd, envp);
			exit_error("execution fail", 127);
		}
		path++;
	}
	exit_error("no executable found", 2);
}

static pid_t	safely_fork(void)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == -1)
		exit_error("fork failed\n", 2);
	return (child_pid);
}

void	child_process(char **argv, char **envp, int *pipe_fd)
{
	int	file_fd;

	file_fd = open(argv[1], O_RDONLY | O_CREAT);
	if (file_fd == -1)
		exit_error("can't open infile\n", 1);
	if (dup2(pipe_fd[WRITE], 1) == -1 || dup2(file_fd, 0) == -1)
		exit_error("dup2 fail\n", 1);
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
	close(file_fd);
	find_and_execute(&argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *pipe_fd)
{
	int	file_fd;

	file_fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (file_fd == -1)
		exit_error("can't open outfile\n", 1);
	if (dup2(pipe_fd[READ], 0) == -1 || dup2(file_fd, 1) == -1)
		exit_error("dup2 fail\n", 1);
	close(pipe_fd[WRITE]);
	close(pipe_fd[READ]);
	close(file_fd);
	find_and_execute(&argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		status;

	if (argc != 5)
		exit_error("invalid nbr of arguments\n", 1);
	if (pipe(pipe_fd) == -1)
		exit_error("pipe creation failed\n", 2);
	pid_1 = safely_fork();
	if (pid_1 == 0)
		child_process(argv, envp, pipe_fd);
	pid_2 = safely_fork();
	if (pid_2 == 0)
		parent_process(argv, envp, pipe_fd);
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
	waitpid(pid_1, &status, 0);
	waitpid(pid_2, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	return (0);
}
