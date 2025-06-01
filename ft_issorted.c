/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:14:47 by feazeved          #+#    #+#             */
/*   Updated: 2025/06/01 19:32:31 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_stack *a)
{
	t_node	*current;
	t_node	*previous_current;

	current = a->top;
	while (current)
	{
		previous_current = current;
		current = current->next;
		if (current && previous_current->index > current->index)
			return (0);
	}
	return (1);
}
