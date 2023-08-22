/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:26:29 by xeherzi           #+#    #+#             */
/*   Updated: 2022/11/27 10:06:06 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*r;

	r = (t_list *)malloc(sizeof(t_list));
	if (!r)
		return (NULL);
	r->content = content;
	r->next = (t_list *)0;
	return (r);
}
