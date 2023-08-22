/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:27:52 by xeherzi           #+#    #+#             */
/*   Updated: 2022/11/14 22:17:07 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*tab;

	tab = (void *)malloc(nitems * size);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, nitems * size);
	return (tab);
}
