/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 01:04:43 by feazeved          #+#    #+#             */
/*   Updated: 2025/06/09 21:14:58 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_index(t_stack *a)
{
	t_node	*inner;
	t_node	*outer;
	int		i;

	outer = a->top;
	while (outer)
	{
		i = 0;
		inner = a->top;
		while (inner)
		{
			if (outer->nbr > inner->nbr)
				i++;
			inner = inner->next;
		}
		outer->index = i;
		outer = outer->next;
	}
}

int	ft_find_pos(t_node **nodes, int *piles, int pile_c, int current)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = pile_c;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (nodes[piles[mid]]->index < nodes[current]->index)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

int	ft_binary_search(t_node **nodes, int *piles, int *ind, int size)
{
	int	i;
	int	pile_count;
	int	position;

	i = 0;
	pile_count = 0;
	while (i < size)
	{
		position = ft_find_pos(nodes, piles, pile_count, i);
		if (position > 0)
			ind[i] = piles[position - 1];
		else
			ind[i] = -1;
		piles[position] = i;
		if (position == pile_count)
			pile_count++;
		i++;
	}
	return (pile_count);
}

int	ft_mark_lis(t_node **nodes, int *piles, int *ind, int pile_c)
{
	int	i;
	int	current;
	int	*lis;

	lis = malloc(sizeof(int) * pile_c);
	if (!lis)
		return (0);
	current = piles[pile_c - 1];
	i = pile_c - 1;
	while (i >= 0)
	{
		lis[i] = current;
		current = ind[current];
		i--;
	}
	i = 0;
	while (i < pile_c)
	{
		nodes[lis[i]]->in_lis = 1;
		i++;
	}
	free(lis);
	return (pile_c);
}

int	ft_find_lis(t_stack *a, t_stack *b, int i)
{
	int		*indexes;
	int		*piles;
	t_node	**nodes;
	t_node	*current;
	int		pile_count;

	nodes = malloc(sizeof(t_node *) * a->size);
	piles = malloc(sizeof(int) * a->size);
	indexes = malloc(sizeof(int) * a->size);
	if (!nodes || !piles || !indexes)
		return (free(nodes), free(piles), free(indexes), ft_error(a, b, NULL));
	current = a->top;
	while (i < a->size)
	{
		nodes[i] = current;
		current = current->next;
		i++;
	}
	pile_count = ft_binary_search(nodes, piles, indexes, a->size);
	pile_count = ft_mark_lis(nodes, piles, indexes, pile_count);
	if (pile_count == 0)
		return (free(nodes), free(piles), free(indexes), ft_error(a, b, NULL));
	return (free(nodes), free(piles), free(indexes), 0);
}
