/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:26:46 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/30 20:04:22 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_find_target(t_stack *a, t_node *temp)
{
	t_node	*current;
	t_node	*target;
	long	best_match;

	current = a->top;
	target = NULL;
	best_match = LONG_MAX;
	while (current)
	{
		if (current->nbr > temp->nbr && current->nbr < best_match)
		{
			best_match = current->nbr;
			target = current;
		}
		current = current->next;
	}
	return (target);
}

static void	ft_set_target(t_stack *a, t_stack *b)
{
	t_node	*b_temp;
	t_node	*temp;
	long	best_match;

	b_temp = b->top;
	while (b_temp)
	{
		b_temp->target = ft_find_target(a, b_temp);
		if (!b_temp->target)
		{
			temp = a->top;
			best_match = LONG_MAX;
			while (temp)
			{
				if (temp->nbr < best_match)
				{
					best_match = temp->nbr;
					b_temp->target = temp;
				}
				temp = temp->next;
			}
		}
		b_temp = b_temp->next;
	}
}

void	ft_set_pos(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		i;

	i = 0;
	if (a)
		current = a->top;
	while (a && current)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
	if (b)
		current = b->top;
	i = 0;
	while (b && current)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
}

static void	ft_set_cost(t_stack *a, t_stack *b)
{
	t_node	*b_current;

	b_current = b->top;
	while (b_current)
	{
		if (b_current->target->pos <= a->size / 2)
			b_current->cost_a = b_current->target->pos;
		else
			b_current->cost_a = -(a->size - b_current->target->pos);
		if (b_current->pos <= b->size / 2)
			b_current->cost_b = b_current->pos;
		else
			b_current->cost_b = -(b->size - b_current->pos);
		b_current = b_current->next;
	}
}

void	ft_set_nodes(t_stack *a, t_stack *b)
{
	ft_set_pos(a, b);
	ft_set_target(a, b);
	ft_set_cost(a, b);
}
