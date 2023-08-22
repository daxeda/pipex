/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:32:20 by xeherzi           #+#    #+#             */
/*   Updated: 2022/11/14 23:01:11 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*result;

	s = (unsigned char *)str;
	while ((n--))
	{
		if (*s != (unsigned char)c)
			s++;
		else
		{
			result = s;
			return (result);
		}
	}
	return (NULL);
}
