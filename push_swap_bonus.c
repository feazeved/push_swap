/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:51:53 by feazeved          #+#    #+#             */
/*   Updated: 2025/06/01 20:29:48 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isvalid(char *line)
{
	int	check;

	check = 0;
	if (!ft_strcmp(line, "sa\n")
		|| !ft_strcmp(line, "sb\n")
		|| !ft_strcmp(line, "ss\n")
		|| !ft_strcmp(line, "pa\n")
		|| !ft_strcmp(line, "pb\n")
		|| !ft_strcmp(line, "ra\n")
		|| !ft_strcmp(line, "rb\n")
		|| !ft_strcmp(line, "rr\n")
		|| !ft_strcmp(line, "rra\n")
		|| !ft_strcmp(line, "rrb\n")
		|| !ft_strcmp(line, "rrr\n"))
		check = 1;
	return (check);
}

void	ft_do_inputs(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0, a, b);
		if (!line)
			break ;
		if (!ft_isvalid(line))
			ft_error(a, b, NULL);
		ft_execute_input(line, a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (1);
	a = init_stack('a');
	b = init_stack('b');
	if (!a || !b || !argv[1][0])
		return (ft_error(a, b, NULL));
	ft_parsing(argc, argv, a, b);
	ft_assign_index(a);
	if (!a->top)
		return (ft_error(a, b, NULL));
	ft_do_inputs(a, b);
	if (ft_issorted(a) && !b->top)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_free_stack(a), ft_free_stack(b), free(a), free(b), 0);
}
