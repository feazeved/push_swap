/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:22:09 by feazeved          #+#    #+#             */
/*   Updated: 2025/06/02 15:54:13 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute_input(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "sa\n"))
		ft_swappation(a);
	else if (!ft_strcmp(line, "sb\n"))
		ft_swappation(b);
	else if (!ft_strcmp(line, "ss\n"))
	{
		ft_swappation(a);
		ft_swappation(b);
	}
	else if (!ft_strcmp(line, "pa\n"))
		ft_pushaition(b, a);
	else if (!ft_strcmp(line, "pb\n"))
		ft_pushaition(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ft_rotation(a);
	else
		ft_execute_input2(line, a, b);
}

void	ft_execute_input2(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "rb\n"))
		ft_rotation(b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		ft_rotation(a);
		ft_rotation(b);
	}
	else if (!ft_strcmp(line, "rra\n"))
		ft_reversation(a);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_reversation(b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		ft_reversation(a);
		ft_reversation(b);
	}
}
