/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:30:57 by feazeved          #+#    #+#             */
/*   Updated: 2025/06/01 19:39:33 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_lis(t_stack *a, t_stack *b)
{
	int	i;
	int	total;

	i = 0;
	total = a->size;
	while (i < total)
	{
		if (a->top->in_lis == 0)
		{
			if (a->top->index > total / 2)
			{
				ft_push(a, b);
				ft_rotate(NULL, b);
			}
			else
				ft_push(a, b);
		}
		else
			ft_rotate(a, NULL);
		i++;
	}
}
