/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:28:57 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/25 23:14:39 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swappation(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	ft_swap(t_stack *a, t_stack *b)
{
	if (a && b && (a->size > 1) && (b->size > 1))
		write(1, "ss\n", 3);
	else if (a && a->size > 1)
		write(1, "sa\n", 3);
	else if (b && b->size > 1)
		write(1, "sb\n", 3);
	ft_swappation(a);
	ft_swappation(b);
}
