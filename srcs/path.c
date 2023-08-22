/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeniaherzi <xeniaherzi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:21:27 by xeherzi           #+#    #+#             */
/*   Updated: 2023/08/22 14:03:13 by xeniaherzi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp, char *cmd)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			if (ft_strlen(envp[i]) < 6)
				error_exit("no local executable AND PATH is unset silly!", 2);
			path = ft_split(&envp[i][5], ':');
			if (!path)
				error_exit("malloc fail (go to jail)\n", 12);
			return (cmd_2_path(path, cmd));
		}
		i++;
	}
	error_exit("NO PATH VAR FOUND IN ENV (or exact path)", 2);
	return (NULL);
}

static int	ptrarrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**cmd_2_path(char **old_path, char *cmd)
{
	char	**proper_path;
	char	*slash_cmd;
	int		i;

	proper_path = malloc((ptrarrlen(old_path) + 1) * sizeof(char *));
	slash_cmd = ft_strjoin("/", cmd);
	if (!proper_path || !slash_cmd)
		error_exit("malloc fail (go to jail)\n", 12);
	i = 0;
	while (old_path[i])
	{
		proper_path[i] = ft_strjoin(old_path[i], slash_cmd);
		if (!proper_path[i])
			error_exit("malloc fail (go to jail)\n", 12);
		free(old_path[i]);
		i++;
	}
	proper_path[i] = NULL;
	free(slash_cmd);
	free(old_path);
	return (proper_path);
}
