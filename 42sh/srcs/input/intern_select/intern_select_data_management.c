/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_select_data_management.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:17:26 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:11 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "input_struct.h"
#include "intern_select.h"
#include "libft.h"
#include <term.h>

void			free_select_data(t_select_data *select_data)
{
	t_select_char	*temp;

	temp = select_data->select_current_case;
	while (temp->previous != NULL)
		temp = temp->previous;
	while (temp->next != NULL)
	{
		temp = temp->next;
		free(temp->previous);
	}
	free(temp);
	free(select_data);
}

void			save_and_free_select_data(t_data *data,
		t_select_data *select_data)
{
	t_select_char	*temp;
	int				index;

	index = 0;
	if (data->clipboard != NULL)
		free(data->clipboard);
	if (!(data->clipboard = (char *)malloc(sizeof(char) *
					(select_data->selection_len + 1))))
		exit(-1);
	data->clipboard[select_data->selection_len] = 0;
	temp = select_data->select_current_case;
	while (temp->previous != NULL)
		temp = temp->previous;
	while (temp->next != NULL)
	{
		data->clipboard[index++] = temp->character;
		temp = temp->next;
		free(temp->previous);
	}
	data->clipboard[index++] = temp->character;
	free(temp);
	free(select_data);
}

static void		set_correct_char(t_data *data, t_reader *read_data,
		t_select_data *select_data)
{
	if (read_data->buffers->next != NULL)
	{
		select_data->current_buffer = read_data->buffers->next;
		select_data->cur_buf_i = 0;
	}
	else
	{
		tputs(data->termcaps->curs_lef, 1, reception);
		select_data->cur_buf_i--;
		select_data->line_i--;
	}
}

t_select_data	*prepare_select_struct(t_data *data,
		t_reader *read_data)
{
	t_select_data	*select_data;

	if (!(select_data = (t_select_data *)malloc(sizeof(t_select_data))))
		exit(-1);
	if (!(select_data->select_begin = (t_select_char *)
				malloc(sizeof(t_select_char))))
		exit(-1);
	select_data->cur_buf_i = read_data->buffers->buf_i;
	select_data->current_buffer = read_data->buffers;
	select_data->line_i = read_data->line_i;
	if (read_data->buffers->buffer[read_data->buffers->buf_i] == 0)
		set_correct_char(data, read_data, select_data);
	select_data->select_current_case = select_data->select_begin;
	select_data->select_begin->character = select_data->
		current_buffer->buffer[select_data->cur_buf_i];
	select_data->select_begin->previous = NULL;
	select_data->select_begin->next = NULL;
	select_data->selection_len = 1;
	return (select_data);
}
