/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:59:06 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/30 21:59:56 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(char c)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->top = NULL;
	new->bottom = NULL;
	new->size = 0;
	new->name = c;
	return (new);
}

t_node	*init_node(long long nbr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = 0;
	new->in_lis = 0;
	new->pos = 0;
	new->target = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_free_stack(t_stack *a)
{
	t_node	*temp;
	t_node	*current;

	current = a->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

int	ft_error(t_stack *a, t_stack *b, char **list)
{
	ft_free_stack(a);
	ft_free_array(list);
	free(a);
	free(b);
	write(2, "Error\n", 6);
	exit(1);
	return (1);
}
