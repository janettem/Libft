/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:07:40 by jmetelin          #+#    #+#             */
/*   Updated: 2020/02/11 13:05:15 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**cpy_str_to_array(char const *s, char c, char **array)
{
	int	i;
	int	j;
	int	start;
	int	len;

	i = 0;
	j = 0;
	while (s[j])
	{
		start = j;
		while (s[j] != c && s[j])
			j++;
		len = j - start;
		if (len > 0)
		{
			if (!(array[i++] = ft_strsub(s, start, len)))
				return (NULL);
		}
		if (s[j])
			j++;
	}
	array[i] = NULL;
	return (array);
}

static int	count_rows(char const *s, char c)
{
	int	rows;

	rows = 1;
	while (*s)
	{
		while (*s != c && *s)
		{
			s++;
			if (*s == c || !*s)
				rows++;
		}
		if (*s)
			s++;
	}
	return (rows);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		rows;

	if (!s)
		return (NULL);
	rows = count_rows(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * rows)))
		return (NULL);
	array = cpy_str_to_array(s, c, array);
	return (array);
}
