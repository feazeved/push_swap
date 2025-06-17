/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:51:04 by feazeved          #+#    #+#             */
/*   Updated: 2025/06/17 17:32:07 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!a->top)
		return (ft_error(a, b, NULL));
	ft_assign_index(a);
	if (ft_issorted(a))
		return (ft_free_stack(a), free(a), free(b), 0);
	if (a->size <= 5)
		return (ft_mini_sort(a, b), ft_free_stack(a),
			ft_free_stack(b), free(a), free(b), 0);
	ft_find_lis(a, b, 0);
	ft_push_lis(a, b);
	ft_sort_list(a, b);
	return (ft_free_stack(a), ft_free_stack(b), free(a), free(b), 0);
}
