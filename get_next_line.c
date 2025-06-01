/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:01:40 by feazeved          #+#    #+#             */
/*   Updated: 2025/05/30 21:42:18 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_line(int fd, t_stack *a, t_stack *b)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			br;
	int			num_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ft_initializer(&line, &br, &num_read);
	while (!br)
	{
		if (!buffer[0])
		{
			num_read = read(fd, buffer, BUFFER_SIZE);
			if (num_read == -1)
				return (free(line), NULL);
			if (num_read == 0)
				break ;
		}
		line = ft_str_join_free(line, buffer, a, b);
		if (!line)
			return (NULL);
		br = ft_clean_buffer(buffer);
	}
	return (line);
}
