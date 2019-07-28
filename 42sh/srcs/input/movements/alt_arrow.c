/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_by_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:53:39 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 01:04:04 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_struct.h"
#include "data_struct.h"
#include "reader.h"
#include <term.h>
#include <stdlib.h>

static int	check_last_line(t_bufstock *buffers)
{
	while (buffers->next != NULL)
	{
		if (buffers->line != buffers->next->line)
			return (1);
		buffers = buffers->next;
	}
	return (0);
}

static void	move_line_down(t_data *data, t_reader *read_data)
{
	int		i;

	i = read_data->line_i;
	cursor_to_end(data, read_data);
	read_data->line_i = 0;
	read_data->buffers = read_data->buffers->next;
	tputs(data->termcaps->curs_line_begin, 1, reception);
	tputs(data->termcaps->curs_down, 1, reception);
	while (read_data->line_i < i
			&& read_data->buffers->buffer[read_data->buffers->buf_i] != '\n'
			&& (read_data->buffers->buffer[read_data->buffers->buf_i] != 0
				|| read_data->buffers->next != NULL))
		right_arrow(data, read_data);
}

static void	up_and_down(t_data *data, t_reader *read_data)
{
	if (read_data->input_buf[3] == 66)
	{
		if (check_last_line(read_data->buffers) == 0)
			new_line(data, read_data);
		else
			move_line_down(data, read_data);
	}
	else
	{
		if (read_data->buffers->line == 0)
			return (ring_bell());
		move_line_up(data, read_data);
	}
}

void		alt_arrow(t_data *data, t_reader *read_data)
{
	if (read_data->input_buf[3] == 68)
	{
		if (read_data->line_i == 0)
			return (ring_bell());
		move_left(data, read_data);
	}
	else if (read_data->input_buf[3] == 67)
	{
		if (read_data->buffers->buffer[read_data->buffers->buf_i] == 0
				&& read_data->buffers->next == NULL)
			return (ring_bell());
		move_right(data, read_data);
	}
	else
		up_and_down(data, read_data);
}
