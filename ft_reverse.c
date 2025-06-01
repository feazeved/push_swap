/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 05:57:29 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/30 17:14:27 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reversation(t_stack *stack)
{
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->bottom;
	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void	ft_reverse(t_stack *a, t_stack *b)
{
	if (a && b && (a->size > 1) && (b->size > 1))
		write(1, "rrr\n", 4);
	else if (a && a->size > 1)
		write(1, "rra\n", 4);
	else if (b && b->size > 1)
		write(1, "rrb\n", 4);
	ft_reversation(a);
	ft_reversation(b);
}
