/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:42:39 by xeherzi           #+#    #+#             */
/*   Updated: 2022/11/14 22:50:41 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	s_dest;
	size_t	s_src;
	size_t	i;

	i = 0;
	s_dest = ft_strlen(dest);
	s_src = ft_strlen(src);
	if (s_dest >= size)
		return (s_src + size);
	while (src[i] && (size - 1 > i + s_dest))
	{
		dest[i + s_dest] = src[i];
		i++;
	}
	dest[i + s_dest] = '\0';
	return (s_dest + s_src);
}
