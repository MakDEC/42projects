/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:04:29 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 16:44:50 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_struct.h"
#include "data_struct.h"
#include "reader.h"
#include "libft.h"
#include <term.h>

static void			end_previous_line(t_data *data, t_reader *read_data)
{
	move_line_up(data, read_data);
	while (read_data->buffers->buffer[read_data->buffers->buf_i] != '\n')
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
		if (read_data->buffers->buffer[read_data->buffers->buf_i] == 0)
			read_data->buffers = read_data->buffers->next;
	}
}

void				left_arrow(t_data *data, t_reader *read_data)
{
	if (read_data->buffers == NULL)
		return ;
	if (read_data->line_i == 0)
	{
		if (read_data->buffers->line > 0)
			end_previous_line(data, read_data);
		else
			ring_bell();
		return ;
	}
	if (read_data->buffers->buf_i == 0)
		read_data->buffers = read_data->buffers->previous;
	tputs(data->termcaps->curs_lef, 1, reception);
	if (read_data->buffers->buf_i == 1
			&& read_data->buffers->buffer[read_data->buffers->buf_i - 1] == ' '
			&& read_data->buffers->previous != NULL)
	{
		read_data->buffers->buf_i--;
		read_data->buffers = read_data->buffers->previous;
	}
	else
		read_data->buffers->buf_i--;
	read_data->line_i--;
}

void				arrow(t_data *data, t_reader *read_data)
{
	if (read_data->input_buf[2] == 'D')
		left_arrow(data, read_data);
	if (read_data->input_buf[2] == 'C')
		right_arrow(data, read_data);
	if (read_data->input_buf[2] == 'A')
		up_arrow(data, read_data);
	if (read_data->input_buf[2] == 'B')
		down_arrow(data, read_data);
}
