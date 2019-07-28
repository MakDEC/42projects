/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_by_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:33:54 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 00:52:46 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_struct.h"
#include "data_struct.h"
#include "reader.h"
#include <stdlib.h>
#include <term.h>

void	move_right(t_data *data, t_reader *read_data)
{
	while (read_data->buffers->buffer[read_data->buffers->buf_i] != 0
			&& read_data->buffers->buffer[read_data->buffers->buf_i] != '\n')
		right_arrow(data, read_data);
	if (read_data->buffers->next != NULL
			&& read_data->buffers->buffer[read_data->buffers->buf_i] != '\n')
		right_arrow(data, read_data);
	while (read_data->buffers->buffer[read_data->buffers->buf_i] == ' '
			|| read_data->buffers->buffer[read_data->buffers->buf_i] == '\t')
		right_arrow(data, read_data);
}

void	move_left(t_data *data, t_reader *read_data)
{
	if ((read_data->buffers->buf_i == 0
				|| read_data->buffers->buffer
				[read_data->buffers->buf_i - 1] == ' '
				|| read_data->buffers->buffer
				[read_data->buffers->buf_i - 1] == '\t')
			&& read_data->buffers->previous != NULL)
	{
		while (read_data->buffers->buf_i > 0)
		{
			tputs(data->termcaps->curs_lef, 1, reception);
			read_data->line_i--;
			read_data->buffers->buf_i--;
		}
		read_data->buffers = read_data->buffers->previous;
	}
	while (read_data->buffers->buf_i > 0
			&& read_data->buffers->buffer
			[read_data->buffers->buf_i - 1] != ' '
			&& read_data->buffers->buffer
			[read_data->buffers->buf_i - 1] != '\t')
	{
		tputs(data->termcaps->curs_lef, 1, reception);
		read_data->line_i--;
		read_data->buffers->buf_i--;
	}
}
