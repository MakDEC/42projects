/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_left_arrow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:16:47 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:11 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "input_struct.h"
#include "libft.h"
#include "intern_select.h"
#include <term.h>

static void			delete_current_case(t_select_data *select_data)
{
	select_data->select_current_case = select_data->
		select_current_case->previous;
	free(select_data->select_current_case->next);
	select_data->select_current_case->next = NULL;
}

static void			create_previous_case(t_select_data *select_data)
{
	if (!(select_data->select_current_case->previous = (t_select_char *)
				malloc(sizeof(t_select_char))))
		exit(-1);
	select_data->select_current_case->previous->next = select_data->
		select_current_case;
	select_data->select_current_case = select_data->
		select_current_case->previous;
	select_data->select_current_case->character = select_data->current_buffer->
		buffer[select_data->cur_buf_i];
	select_data->select_current_case->previous = NULL;
}

static void			adjust_select_data(t_data *data,
		t_select_data *select_data)
{
	if (select_data->cur_buf_i == 0)
	{
		select_data->current_buffer = select_data->current_buffer->previous;
		select_data->cur_buf_i = ft_strlen(
				select_data->current_buffer->buffer) - 1;
	}
	else
		select_data->cur_buf_i--;
	select_data->line_i--;
	tputs(data->termcaps->curs_lef, 1, reception);
	return ;
}

void				select_left_arrow(t_data *data, t_select_data *select_data)
{
	if (select_data->line_i == 0)
	{
		write(1, "\a", 1);
		return ;
	}
	else if (select_data->select_current_case->previous == NULL)
	{
		adjust_select_data(data, select_data);
		write_reverse_char(select_data, 1);
		create_previous_case(select_data);
		select_data->selection_len += 1;
	}
	else
	{
		write_normal_char_keep_cursor_unchanged(select_data);
		delete_current_case(select_data);
		adjust_select_data(data, select_data);
		select_data->selection_len -= 1;
	}
	return ;
}
