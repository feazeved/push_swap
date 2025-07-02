/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:42:55 by feazeved          #+#    #+#             */
/*   Updated: 2025/07/02 20:52:25 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_abs(int cost)
{
	if (cost < 0)
		cost = -cost;
	return (cost);
}

t_node	*ft_find_cheapest(t_stack *b, int *check)
{
	t_node	*current;
	t_node	*cheapest;

	cheapest = NULL;
	current = b->top;
	while (current)
	{
		if (!cheapest || (abs(cheapest->cost_a) + abs(cheapest->cost_b)
				> (abs(current->cost_a) + abs(current->cost_b))))
			cheapest = current;
		current = current->next;
	}
	if (cheapest->cost_a >= 0 && cheapest->cost_b >= 0)
		*check = 1;
	else if (cheapest->cost_a <= 0 && cheapest->cost_b <= 0)
		*check = 2;
	else
		*check = 0;
	return (cheapest);
}

void	ft_final_sort(t_stack *a)
{
	t_node	*current;
	int		lowest_pos;

	ft_set_pos(a, NULL);
	current = a->top;
	lowest_pos = 0;
	while (current)
	{
		if (current->index == 0)
		{
			lowest_pos = current->pos;
			break ;
		}
		current = current->next;
	}
	if (lowest_pos < a->size / 2)
	{
		while (lowest_pos-- > 0)
			ft_rotate(a, NULL);
		return ;
	}
	lowest_pos = a->size - lowest_pos;
	while (lowest_pos-- > 0)
		ft_reverse(a, NULL);
}

void	ft_movements(t_stack *a, t_stack *b, t_node	*to_sort)
{
	while (to_sort->cost_a > 0)
	{
		ft_rotate (a, NULL);
		to_sort->cost_a--;
	}
	while (to_sort->cost_a < 0)
	{
		ft_reverse(a, NULL);
		to_sort->cost_a++;
	}
	while (to_sort->cost_b > 0)
	{
		ft_rotate(NULL, b);
		to_sort->cost_b--;
	}
	while (to_sort->cost_b < 0)
	{
		ft_reverse(NULL, b);
		to_sort->cost_b++;
	}
	ft_push(b, a);
}

void	ft_sort_list(t_stack *a, t_stack *b)
{
	int		check;
	t_node	*to_sort;

	while (1)
	{
		if (!b->top)
			break ;
		ft_set_nodes(a, b);
		to_sort = ft_find_cheapest(b, &check);
		while (check == 1 && to_sort->cost_a && to_sort->cost_b)
		{
			ft_rotate(a, b);
			to_sort->cost_a--;
			to_sort->cost_b--;
		}
		while (check == 2 && to_sort->cost_a && to_sort->cost_b)
		{
			ft_reverse(a, b);
			to_sort->cost_a++;
			to_sort->cost_b++;
		}
		ft_movements(a, b, to_sort);
	}
	ft_final_sort(a);
}
