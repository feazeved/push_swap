/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:59:07 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/20 23:06:17 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countwords(char const *str, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			counter++;
		while (str[i] != c && str[i])
			i++;
	}
	return (counter);
}

static int	ft_sep_strlen(const char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] != sep && str[i])
		i++;
	return (i);
}

static char	*ft_sep_strcpy(const char *src, char sep)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_sep_strlen(src, sep);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		i;
	int		words;

	i = 0;
	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	array = ft_calloc((words + 1), sizeof(char *));
	if (!array)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			array[i] = ft_sep_strcpy(s, c);
			if (!array[i++])
				return (ft_free_array(array), NULL);
			s += ft_sep_strlen(s, c);
		}
	}
	return (array);
}
