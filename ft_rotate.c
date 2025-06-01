/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:16:35 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/25 23:17:03 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotation(t_stack *stack)
{
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	stack->bottom->next = first;
	first->prev = stack->bottom;
	first->next = NULL;
	stack->bottom = first;
}

void	ft_rotate(t_stack *a, t_stack *b)
{
	if (a && b && (a->size > 1) && (b->size > 1))
		write(1, "rr\n", 3);
	else if (a && a->size > 1)
		write(1, "ra\n", 3);
	else if (b && b->size > 1)
		write(1, "rb\n", 3);
	ft_rotation(a);
	ft_rotation(b);
}
