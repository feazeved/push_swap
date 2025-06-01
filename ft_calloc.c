/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:39:38 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/28 21:58:08 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			a;
	unsigned char	*ptr;

	i = 0;
	a = nmemb * size;
	if (size && (a / size != nmemb))
		return (NULL);
	ptr = malloc(a);
	if (!ptr)
		return (NULL);
	while (i < a)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
int	main(int argc, char *argv[])
{
	unsigned long	i = 0;
	char	*f = "arara";
	char	*c = ft_calloc(ft_strlen(f), sizeof(char));
//	char	*c = calloc(ft_strlen(f), sizeof(char));

	(void)argc;
	(void)argv;
//	while (i <= (ft_strlen(f) * sizeof(char)))
//	{
//		printf("%d\n", c[i++]);
//	}
	while (i < (ft_strlen(f)))
	{
		printf("%d\n", c[i++]);
	}
	free(c);
	return (0);
}*/
