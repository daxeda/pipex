/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:21:27 by xeherzi           #+#    #+#             */
/*   Updated: 2023/08/23 13:03:59 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp, char *cmd)
{
	int		index;
	char	**search_path;

	index = 0;
	while (envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
		{
			if (ft_strlen(envp[index]) < 6)
				exit_error("no local executable AND PATH not set!", 2);
			search_path = ft_split(&envp[index][5], ':');
			if (!search_path)
				exit_error("malloc fail\n", 12);
			return (cmd_2_path(search_path, cmd));
		}
		index++;
	}
	exit_error("no PATH variable found in env or exact", 2);
	return (NULL);
}

static int	count_ptraritems(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

char	**cmd_2_path(char **old_path, char *cmd)
{
	char	**proper_path;
	char	*slash_cmd;
	int		i;

	proper_path = malloc((count_ptraritems(old_path) + 1) * sizeof(char *));
	slash_cmd = ft_strjoin("/", cmd);
	if (!proper_path || !slash_cmd)
		exit_error("malloc fail\n", 12);
	i = 0;
	while (old_path[i])
	{
		proper_path[i] = ft_strjoin(old_path[i], slash_cmd);
		if (!proper_path[i])
			exit_error("malloc fail\n", 12);
		free(old_path[i]);
		i++;
	}
	proper_path[i] = NULL;
	free(slash_cmd);
	free(old_path);
	return (proper_path);
}
