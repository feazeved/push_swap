# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 23:18:00 by feazeved          #+#    #+#              #
#    Updated: 2025/07/02 20:27:06 by feazeved         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c ft_calloc.c ft_find_lis.c ft_parsing.c ft_split.c ft_push.c ft_push_lis.c \
ft_reverse.c ft_rotate.c ft_set_nodes.c ft_swap.c ft_issorted.c ft_sort_list.c ft_mini_sort.c push_swap_utils.c\

SRC_BONUS = push_swap_bonus.c ft_calloc.c ft_find_lis.c ft_parsing.c ft_split.c ft_push.c ft_push_lis.c \
ft_reverse.c ft_rotate.c ft_set_nodes.c ft_swap.c ft_issorted.c ft_sort_list.c ft_mini_sort.c \
get_next_line.c get_next_line_utils.c push_swap_utils.c ft_execute_input.c

OBJS = $(SRC:.c=.o)

BOBJS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: .bonus

.bonus: $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(NAME_BONUS)
	touch .bonus

clean:
	$(RM) $(OBJS) $(BOBJS)
	$(RM) .bonus

fclean: clean
	$(RM) push_swap
	$(RM) $(NAME_BONUS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@


re: fclean all
