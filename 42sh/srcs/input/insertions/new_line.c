/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:15:50 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 01:02:23 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_struct.h"
#include "data_struct.h"
#include "reader.h"
#include <stdlib.h>
#include <unistd.h>

static void	reset_line_tools(t_bufstock *buffers)
{
	while (buffers->previous != NULL
			&& buffers->line == buffers->previous->line)
	{
		buffers->buf_i = 0;
		buffers = buffers->previous;
	}
	buffers->buf_i = 0;
}

void		new_line(t_data *data, t_reader *read_data)
{
	cursor_to_end(data, read_data);
	read_data->buffers->buffer[read_data->buffers->buf_i] = '\n';
	reset_line_tools(read_data->buffers);
	write(1, "\n", 1);
	read_data->buffers->next = new_buffers_node(read_data->buffers,
			NULL, read_data->buffers->line + 1, 0);
	read_data->buffers = read_data->buffers->next;
	read_data->line_i = 0;
}
