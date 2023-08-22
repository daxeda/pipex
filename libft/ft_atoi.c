/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:12:02 by xeherzi           #+#    #+#             */
/*   Updated: 2022/11/27 10:09:16 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_signe(const char *str)
{
	int	i;

	i = 0;
	while ((!(str[i] >= '0' && str[i] <= '9')) && str[i] != '-'
		&& str[i] != '+')
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] <= '9' && str[i + 1] >= '0')
		{
			if (str[i] == '-')
				return (-1);
			return (1);
		}
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	i;

	i = 0;
	number = 0;
	while (!(str[i] >= '0' && str[i] <= '9') && str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\f' && str[i] != '\v' && str[i] != '\r'
			&& str[i] != '+' && str[i] != '-')
			return (0);
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * ft_signe(str));
}
