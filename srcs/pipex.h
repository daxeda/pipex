/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:21:08 by xeherzi           #+#    #+#             */
/*   Updated: 2023/08/23 13:12:53 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h> 
# include <fcntl.h>
# include "../libft/libft.h"
# include <sys/stat.h>

# define READ 0
# define WRITE 1

static int			count_ptraritems(char **arr);
char				**cmd_2_path(char **old_path, char *cmd);
void				find_and_execute(char **cmd, char **env);
void				child_process(char **argv, char **envp, int *pipe_fd);
void				parent_process(char **argv, char **envp, int *pipe_fd);
static pid_t		safely_fork(void);
void				exit_error(const char *message, int exit_code);
char				**find_path(char **envp, char *cmd);

#endif 