/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:12:27 by xeherzi           #+#    #+#             */
/*   Updated: 2022/11/14 15:06:46 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	*ft_len_strs(char *str, char c, int n_words)
{
	int	index;
	int	len;
	int	*len_strs;

	len_strs = malloc(sizeof(int) * n_words);
	if (len_strs == 0)
		return (0);
	index = 0;
	while (*str)
	{
		if (*str != c)
		{
			len = 0;
			while (*str && *str != c)
			{
				str++;
				len++;
			}
			len_strs[index++] = len + 1;
		}
		else
			str++;
	}
	return (len_strs);
}

static char	**ft_free_split(char **dst, size_t i)
{
	size_t	k;

	k = 0;
	while (k < i)
		free(dst[k++]);
	free(dst);
	return (NULL);
}

static char	**ft_fill_big_table(char *src, char c, char **dst, int *lens)
{
	int	j;
	int	count;

	count = 0;
	while (*src)
	{
		if (*src != c)
		{
			dst[count] = malloc(sizeof(char) * lens[count]);
			if (dst[count] == NULL)
				return (ft_free_split(dst, count));
			j = 0;
			while (*src && *src != c)
				dst[count][j++] = *src++;
			dst[count++][j] = '\0';
		}
		else
			src++;
	}
	dst[count] = NULL;
	free(lens);
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	*src;
	char	**dst;
	int		*lens;
	int		count;

	src = (char *)s;
	count = ft_n_words(src, c);
	lens = ft_len_strs(src, c, count);
	dst = malloc(sizeof(char *) * count);
	if (dst == NULL)
		return (NULL);
	return (ft_fill_big_table(src, c, dst, lens));
}
