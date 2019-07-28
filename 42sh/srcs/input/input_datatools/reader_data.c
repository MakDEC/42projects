/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 02:13:45 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:10 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_struct.h"
#include "data_struct.h"
#include "libft.h"

int			set_initiale_cursor_position(t_data *data, t_reader *read_data)
{
	char				buf[17];
	ssize_t				rd;

	if (write(STDOUT_FILENO, "\033[6n", 4) == -1)
		return (-1);
	if ((rd = read(STDIN_FILENO, buf, 16)) == -1 || buf[rd - 1] != 'R')
		return (-1);
	buf[rd] = 0;
	read_data->initiale_cursor_position[0] = ft_atoi(buf + 2) - 1;
	rd = 2;
	while (buf[rd] && buf[rd] != ';')
		++rd;
	read_data->initiale_cursor_position[1] = ft_atoi(buf + rd + 1) - 1;
	read_data->col_line_0 = (data->screen_width
			- read_data->initiale_cursor_position[1]);
	return (0);
}

void		free_bufstock(t_bufstock *buffers)
{
	if (buffers == NULL)
		return ;
	while (buffers->next != NULL)
	{
		if (buffers->previous != NULL)
		{
			free(buffers->previous);
			buffers->previous = NULL;
		}
		if (buffers->buffer != NULL)
		{
			free(buffers->buffer);
			buffers->buffer = NULL;
		}
		buffers = buffers->next;
	}
	if (buffers->previous != NULL)
		free(buffers->previous);
	if (buffers->buffer != NULL)
	{
		free(buffers->buffer);
		buffers->buffer = NULL;
	}
	free(buffers);
}

t_bufstock	*delete_buffers_node(t_bufstock *buffers)
{
	t_bufstock	*temp;

	free(buffers->buffer);
	buffers->buffer = NULL;
	temp = buffers->next;
	buffers = buffers->previous;
	free(buffers->next);
	buffers->next = temp;
	return (buffers);
}

t_bufstock	*new_buffers_node(t_bufstock *previous, t_bufstock *next,
		int line, int is_com)
{
	t_bufstock	*buffers;

	if (!(buffers = (t_bufstock*)malloc(sizeof(t_bufstock))))
		exit(-1);
	if (!(buffers->buffer = (char*)malloc(sizeof(char) * 512)))
		exit(-1);
	ft_bzero(buffers->buffer, 512);
	buffers->line = line;
	buffers->next = next;
	buffers->previous = previous;
	buffers->is_com = is_com;
	buffers->buf_i = 0;
	return (buffers);
}

t_reader	*init_reader_data(t_data *data)
{
	t_reader	*reader;

	if (!(reader = (t_reader*)malloc(sizeof(t_reader))))
		exit(-1);
	reader->buffers = new_buffers_node(NULL, NULL, 0, 1);
	reader->begin = reader->buffers;
	ft_bzero(reader->input_buf, 5);
	set_initiale_cursor_position(data, reader);
	reader->line_i = 0;
	reader->ret_read = 0;
	reader->ret_read_buf = 1;
	reader->temp = NULL;
	reader->temp_his = data->history;
	return (reader);
}
