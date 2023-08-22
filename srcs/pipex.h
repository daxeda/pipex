/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:21:08 by xeherzi           #+#    #+#             */
/*   Updated: 2023/08/22 16:23:11 by xeherzi          ###   ########.fr       */
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

# define READ 0
# define WRITE 1

char	**find_executable_path(char **envp, char *cmd);
char	**cmd_2_path(char **old_path, char *cmd);
void	exit_with_error(const char *message, int exit_code);
char	**convert_to_full_path(char **old_path, char *cmd);
char	**find_path(char **envp, char *cmd);
void	error_exit(const char *message, int exit_code);

#endif 