/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:07:21 by xeherzi           #+#    #+#             */
/*   Updated: 2023/08/22 16:16:36 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_and_exec(char **cmd, char **envp)
{
	char	**path;

	if (ft_strchr(*cmd, ' '))
		cmd = ft_split(*cmd, ' ');
	if (!cmd)
		error_exit("malloc fail\n", 12);
	if (access(*cmd, F_OK | X_OK) == 0)
	{
		execve(*cmd, cmd, envp);
		error_exit("exec fail\n", 127);
	}
	path = find_path(envp, *cmd);
	if (!path)
		error_exit("malloc fail\n", 12);
	while (path)
	{
		if (access(*path, F_OK | X_OK) == 0)
		{
			execve(*path, cmd, envp);
			error_exit("exec fail", 127);
		}
		path++;
	}
	error_exit("No executable found", 2);
}

void	baby_1(char **argv, char **envp, int *pipe_fd)
{
	int	file_fd;

	file_fd = open(argv[1], O_RDONLY);
	if (file_fd == -1)
		error_exit("can't open infile\n", 1);
	if (dup2(pipe_fd[WRITE], 1) == -1 || dup2(file_fd, 0) == -1)
		error_exit("dup2 fail\n", 1);
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
	close(file_fd);
	find_and_exec(&argv[2], envp);
}

void	baby_2(char **argv, char **envp, int *pipe_fd)
{
	int	file_fd;

	file_fd = open(argv[4], O_WRONLY | O_TRUNC);
	if (file_fd == -1)
		error_exit("can't open outfile\n", 1);
	if (dup2(pipe_fd[READ], 0) == -1 || dup2(file_fd, 1) == -1)
		error_exit("dup2 fail\n", 1);
	close(pipe_fd[WRITE]);
	close(pipe_fd[READ]);
	close(file_fd);
	find_and_exec(&argv[3], envp);
}

static pid_t	safe_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("fork failed\n", 2);
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		stat_loc;

	if (argc != 5)
		error_exit("wrong nr of arguments\n", 1);
	if (pipe(pipe_fd) == -1)
		error_exit("pipe failed\n", 2);
	pid_1 = safe_fork();
	if (pid_1 == 0)
		baby_1(argv, envp, pipe_fd);
	pid_2 = safe_fork();
	if (pid_2 == 0)
		baby_2(argv, envp, pipe_fd);
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
	waitpid(pid_1, &stat_loc, 0);
	waitpid(pid_2, &stat_loc, 0);
	if (WIFEXITED(stat_loc))
		exit(WEXITSTATUS(stat_loc));
	return (0);
}
