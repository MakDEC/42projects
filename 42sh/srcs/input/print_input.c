/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:44:39 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 01:48:37 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "data_struct.h"
#include "libft.h"
#include "reader.h"

static int			last_col_i_given(t_data *data, t_reader *read_data, int i)
{
	if (read_data->buffers->line == 0)
		i += data->prompt_size;
	while (i > data->screen_width)
		i -= data->screen_width;
	if (i == 0)
		return (-1);
	return (i % data->screen_width);
}

void				reprint_after_backspace(t_data *data, t_reader *read_data)
{
	t_bufstock	*temp;

	temp = read_data->buffers;
	tputs(data->termcaps->curs_lef, 1, reception);
	tputs(data->termcaps->saving_cursor, 1, reception);
	tputs(data->termcaps->clear_down, 1, reception);
	ft_putstr(&temp->buffer[temp->buf_i]);
	temp = temp->next;
	while (temp != NULL)
	{
		ft_putstr(temp->buffer);
		temp = temp->next;
	}
	tputs(data->termcaps->restor_cursor, 1, reception);
}

void				reprint_input(t_data *data, t_reader *read_data)
{
	t_bufstock	*temp;

	temp = read_data->buffers;
	tputs(data->termcaps->saving_cursor, 1, reception);
	tputs(data->termcaps->clear_down, 1, reception);
	if (temp->buf_i > 0)
		ft_putstr(&temp->buffer[temp->buf_i - 1]);
	temp = temp->next;
	while (temp != NULL)
	{
		ft_putstr(temp->buffer);
		temp = temp->next;
	}
	tputs(data->termcaps->restor_cursor, 1, reception);
	if (last_col_i_given(data, read_data, read_data->buffers->buf_i) > 0)
		tputs(data->termcaps->curs_ri, 1, reception);
	else
	{
		tputs(data->termcaps->curs_line_begin, 1, reception);
		tputs(data->termcaps->curs_down, 1, reception);
	}
}
