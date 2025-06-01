/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 00:59:40 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/30 15:57:05 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parsing(int argc, char *argv[], t_stack *a, t_stack *b)
{
	int		i;
	char	**list;

	if (argc == 2)
	{
		i = 0;
		list = ft_split(argv[1], ' ');
		while (list[i])
			ft_putnode(ft_strtol(list[i++]), a, b, list);
		ft_free_array(list);
	}
	else
	{
		i = 1;
		while (i < argc)
			ft_putnode(ft_strtol(argv[i++]), a, b, NULL);
	}
	ft_set_stack(a);
}

void	ft_set_stack(t_stack *a)
{
	int		len;
	t_node	*temp;

	len = 0;
	temp = a->top;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	a->size = len;
	temp = a->top;
	while (temp && temp->next)
		temp = temp->next;
	a->bottom = temp;
}

int	ft_isdouble(long long nbr, t_stack *a)
{
	t_node	*temp;

	temp = a->top;
	while (temp)
	{
		if (nbr == temp->nbr)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_putnode(long long nbr, t_stack *a, t_stack *b, char **list)
{
	t_node	*new;
	t_node	*temp;

	if (nbr == LONG_MAX || ft_isdouble(nbr, a))
		ft_error(a, b, list);
	new = init_node(nbr);
	if (!new)
		ft_error(a, b, list);
	if (a->top == NULL)
	{
		a->top = new;
		return ;
	}
	temp = a->top;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

long long	ft_strtol(char *arg)
{
	long long	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	while (*arg == ' ' || (*arg >= 9 && *arg <= 13))
		arg++;
	if (*arg == '+' || *arg == '-')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
	}
	if (!(*arg))
		return (LONG_MAX);
	while (*arg >= '0' && *arg <= '9')
	{
		nbr = *arg++ - '0' + (nbr * 10);
		if (nbr * sign > INT_MAX || nbr * sign < INT_MIN)
			return (LONG_MAX);
	}
	if (*arg)
		return (LONG_MAX);
	return (nbr * sign);
}
