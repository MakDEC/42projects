/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:47:57 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:12 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "reader.h"
#include <stdlib.h>

static void		cursor_to_end2(t_data *data, t_reader *read_data)
{
	while (read_data->buffers->buffer[read_data->buffers->buf_i] != 0
			&& read_data->buffers->buffer[read_data->buffers->buf_i] != '\n')
	{
		if (last_col(data, read_data) == 0)
		{
			tputs(data->termcaps->curs_line_begin, 1, reception);
			tputs(data->termcaps->curs_down, 1, reception);
		}
		else
			tputs(data->termcaps->curs_ri, 1, reception);
		read_data->buffers->buf_i++;
		read_data->line_i++;
	}
}

void			cursor_to_end(t_data *data, t_reader *read_data)
{
	while (read_data->buffers->next != NULL
			&& read_data->buffers->buffer[read_data->buffers->buf_i] != '\n')
	{
		while (read_data->buffers->buffer[read_data->buffers->buf_i] != 0
				&& read_data->buffers->buffer
				[read_data->buffers->buf_i] != '\n')
		{
			if (last_col(data, read_data) == 0)
			{
				tputs(data->termcaps->curs_line_begin, 1, reception);
				tputs(data->termcaps->curs_down, 1, reception);
			}
			else
				tputs(data->termcaps->curs_ri, 1, reception);
			read_data->buffers->buf_i++;
			read_data->line_i++;
		}
		if (read_data->buffers->buffer[read_data->buffers->buf_i] != '\n')
			read_data->buffers = read_data->buffers->next;
	}
	cursor_to_end2(data, read_data);
}

void			back_to_begin(t_data *data, t_reader *read_data)
{
	while (read_data->buffers->previous != NULL
			&& (read_data->buffers->line == read_data->buffers->previous->line))
	{
		while (read_data->buffers->buf_i > 0)
			left_arrow(data, read_data);
	}
	while (read_data->buffers->buf_i > 0)
		left_arrow(data, read_data);
}
