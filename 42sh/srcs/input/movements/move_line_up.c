/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_line_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 04:00:21 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 01:08:29 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "reader.h"
#include <term.h>
#include "libft.h"

int			line_width(t_data *data, t_reader *read_data)
{
	int			line_width;
	t_bufstock	*temp;

	line_width = 0;
	temp = read_data->buffers;
	while (temp->previous != NULL
			&& temp->line == temp->previous->line)
	{
		line_width += ft_strlen(temp->buffer);
		temp = temp->previous;
	}
	line_width += ft_strlen(temp->buffer);
	if (temp->line == 0)
		line_width += (data->screen_width - read_data->col_line_0);
	return (line_width);
}

static void	align_prompt(t_data *data, t_reader *read_data)
{
	int		to_reach;

	to_reach = data->screen_width - read_data->col_line_0;
	while (--to_reach > 0)
		tputs(data->termcaps->curs_ri, 1, reception);
}

static void	reset_line_tools(t_reader *read_data)
{
	while (read_data->buffers->previous != NULL
			&& read_data->buffers->line == read_data->buffers->previous->line)
	{
		read_data->buffers->buf_i = 0;
		read_data->buffers = read_data->buffers->previous;
	}
	read_data->buffers->buf_i = 0;
	read_data->line_i = 0;
}

void		move_line_up(t_data *data, t_reader *read_data)
{
	int			i;
	int			line_wid;

	if (read_data->buffers->line == 0)
		return ;
	i = read_data->line_i;
	back_to_begin(data, read_data);
	read_data->buffers = read_data->buffers->previous;
	line_wid = line_width(data, read_data);
	reset_line_tools(read_data);
	while (line_wid > 0)
	{
		tputs(data->termcaps->curs_up, 1, reception);
		line_wid -= data->screen_width;
	}
	if (read_data->buffers->line == 0)
		align_prompt(data, read_data);
	while (read_data->line_i < i
			&& read_data->buffers->line == read_data->buffers->next->line
			&& read_data->buffers->buffer[read_data->buffers->buf_i] != '\n')
		right_arrow(data, read_data);
	while (read_data->line_i < i && read_data->buffers->buffer
			[read_data->buffers->buf_i] != '\n')
		right_arrow(data, read_data);
}
