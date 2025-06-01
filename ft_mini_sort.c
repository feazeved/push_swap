/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:13:06 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/30 17:13:15 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_max_index(t_stack *a)
{
	t_node	*current;

	current = a->top;
	if (current->index < current->next->index)
		current = current->next;
	if (current->index < a->bottom->index)
		current = a->bottom;
	return (current);
}

void	ft_five_sort(t_stack *a, t_stack *b)
{
	t_node	*current;

	ft_push(a, b);
	ft_push(a, b);
	ft_set_pos(a, b);
	current = ft_max_index(a);
	if (current->pos == 0)
		ft_rotate(a, NULL);
	else if (current->pos == 1)
		ft_reverse(a, NULL);
	if (a->top->index > a->top->next->index)
		ft_swap(a, NULL);
	ft_sort_list(a, b);
}

void	ft_mini_sort(t_stack *a, t_stack *b)
{
	if (a->size == 3)
	{
		if (a->top->index == 2)
			ft_rotate(a, NULL);
		else if (a->top->next->index == 2)
			ft_reverse(a, NULL);
		if (a->top->index > a->top->next->index)
			ft_swap(a, NULL);
	}
	else if (a->size == 2)
		ft_swap(a, NULL);
	else
		ft_five_sort(a, b);
}
