/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:32:44 by xeherzi           #+#    #+#             */
/*   Updated: 2022/11/14 22:15:19 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*result;

	result = NULL;
	while (*str)
	{
		if (*str == (char) c)
			result = (char *)str;
		str++;
	}
	if (*str == (char) c)
		result = (char *)str;
	return (result);
}
