/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:55:54 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 01:09:13 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "data_struct.h"
#include "input_struct.h"
#include "libft.h"
#include "reader.h"

static void			reset_line_tools(t_bufstock *buffers)
{
	while (buffers->previous != NULL
			&& buffers->line == buffers->previous->line)
	{
		buffers->buf_i = 0;
		buffers = buffers->previous;
	}
	buffers->buf_i = 0;
}

int					last_col(t_data *data, t_reader *read_data)
{
	int		cpy_line_i;

	cpy_line_i = read_data->line_i + 1;
	if (read_data->buffers->line == 0)
		cpy_line_i += data->prompt_size;
	while (cpy_line_i > data->screen_width)
		cpy_line_i -= data->screen_width;
	return (cpy_line_i % data->screen_width);
}

void				right_arrow(t_data *data, t_reader *read_data)
{
	if (read_data->buffers->buffer[read_data->buffers->buf_i] == 0
			&& read_data->buffers->next == NULL)
		return (ring_bell());
	if (read_data->buffers->buffer[read_data->buffers->buf_i] == '\n')
	{
		reset_line_tools(read_data->buffers);
		tputs(data->termcaps->curs_line_begin, 1, reception);
		tputs(data->termcaps->curs_down, 1, reception);
		read_data->buffers = read_data->buffers->next;
		read_data->line_i = 0;
		return ;
	}
	else if (read_data->buffers->buffer[read_data->buffers->buf_i] == 0)
		read_data->buffers = read_data->buffers->next;
	if (last_col(data, read_data) == 0)
	{
		tputs(data->termcaps->curs_line_begin, 1, reception);
		tputs(data->termcaps->curs_down, 1, reception);
	}
	else
		tputs(data->termcaps->curs_ri, 0, reception);
	read_data->buffers->buf_i++;
	read_data->line_i++;
}
