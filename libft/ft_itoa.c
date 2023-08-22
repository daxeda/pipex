/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:37:34 by xeherzi           #+#    #+#             */
/*   Updated: 2022/11/14 17:03:33 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sizeofn(int n)
{
	int	n_size;

	n_size = 0;
	if (n < 0)
	{
		n = -n;
		n_size++;
	}
	while (n > 9)
	{
		n /= 10;
		n_size++;
	}
	n_size++;
	return (n_size);
}

char	*ft_itoa(int n)
{
	int		n_size;
	char	*result;
	int		i;

	i = 0;
	n_size = sizeofn(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc((n_size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	while (n > 9)
	{
		result[n_size - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	result[n_size - i - 1] = n % 10 + '0';
	result[n_size] = '\0';
	return (result);
}
