/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:44:50 by feazeved          #+#    #+#             */
/*   Updated: 2025/06/17 17:29:09 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushaition(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (!from->top)
		return ;
	node = from->top;
	from->top = node->next;
	if (from->top)
		from->top->prev = NULL;
	else
		from->bottom = NULL;
	from->size--;
	node->next = to->top;
	if (to->top)
		to->top->prev = node;
	else
		to->bottom = node;
	node->prev = NULL;
	to->top = node;
	to->size++;
}

void	ft_push(t_stack *from, t_stack *to)
{
	if (!from || from->size == 0)
		return ;
	if (to->name == 'a')
		write(1, "pa\n", 3);
	else if (to->name == 'b')
		write(1, "pb\n", 3);
	ft_pushaition(from, to);
}
