/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:05:22 by feazeved          #+#    #+#             */
/*   Updated: 2025/06/07 23:04:51 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define BUFFER_SIZE 12

typedef struct s_node
{
	long long		nbr;
	int				index;
	int				in_lis;
	int				pos;
	struct s_node	*target;
	int				cost_a;
	int				cost_b;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
	char	name;
}	t_stack;

void		ft_set_pos(t_stack *a, t_stack *b);
int			ft_find_lis(t_stack *a, t_stack *b, int i);
int			ft_mark_lis(t_node **nodes, int *piles, int *ind, int pile_c);
int			ft_binary_search(t_node **nodes, int *piles, int *ind, int size);
int			ft_issorted(t_stack *a);
int			ft_find_pos(t_node **nodes, int *piles, int pile_c, int current);
void		ft_free_array(char **array);
void		*ft_calloc(size_t nmemb, size_t size);
char		**ft_split(const char *s, char c);
int			ft_error(t_stack *a, t_stack *b, char **list);
void		ft_free_stack(t_stack *a);
long long	ft_strtol(char *arg);
t_node		*init_node(long long nbr);
void		ft_putnode(long long nbr, t_stack *a, t_stack *b, char **list);
int			ft_isdouble(long long nbr, t_stack *a);
void		ft_set_stack(t_stack *a);
void		ft_parsing(int argc, char *argv[], t_stack *a, t_stack *b);
void		ft_assign_index(t_stack *a);
t_stack		*init_stack(char c);
void		ft_push(t_stack *from, t_stack *to);
void		ft_rotate(t_stack *a, t_stack *b);
void		ft_push_lis(t_stack *a, t_stack *b);
void		ft_push(t_stack *from, t_stack *to);
void		ft_reverse(t_stack *a, t_stack *b);
void		ft_rotate(t_stack *a, t_stack *b);
void		ft_set_nodes(t_stack *a, t_stack *b);
void		ft_sort_list(t_stack *a, t_stack *b);
void		ft_swap(t_stack *a, t_stack *b);
void		ft_mini_sort(t_stack *a, t_stack *b);
void		ft_initializer(char **line, int *br, int *num_read);
char		*get_next_line(int fd, t_stack *a, t_stack *b);
int			ft_strlen_line(char *str);
int			ft_clean_buffer(char *buffer);
char		*ft_str_join_free(char *old, char *buffer, t_stack *a, t_stack *b);
void		ft_rotation(t_stack *stack);
void		ft_reversation(t_stack *stack);
void		ft_swappation(t_stack *stack);
void		ft_pushaition(t_stack *from, t_stack *to);
void		ft_execute_input2(char *line, t_stack *a, t_stack *b);
void		ft_execute_input(char *line, t_stack *a, t_stack *b);
int			ft_strcmp(char *s1, char *s2);

#endif
