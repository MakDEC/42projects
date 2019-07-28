/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_concat_result.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:07:33 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:08 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"
#include "input_struct.h"
#include "reader.h"
#include <term.h>

static void		print_after_new_word(t_data *data, t_reader *read_data)
{
	t_bufstock		*temp_ptr;

	temp_ptr = read_data->buffers->next;
	tputs(data->termcaps->saving_cursor, 1, reception);
	while (temp_ptr != NULL)
	{
		ft_putstr(temp_ptr->buffer);
		temp_ptr = temp_ptr->next;
	}
	tputs(data->termcaps->restor_cursor, 1, reception);
}

void			concat_word_in_buf_and_print_it(t_data *data,
		t_reader *read_data, t_completion *comp_data)
{
	char			*ptr_on_rest;

	ptr_on_rest = &comp_data->ptr_on_possibilities_list
		->matching_word[comp_data->current_word_to_comp_size];
	ft_strcat(read_data->buffers->buffer, ptr_on_rest);
	if (comp_data->ptr_on_possibilities_list->is_reg_file == 0)
		ft_strcat(read_data->buffers->buffer, "/");
	ft_putstr(&read_data->buffers->buffer[read_data->buffers->buf_i]);
	while (read_data->buffers->buffer[read_data->buffers->buf_i] != 0)
	{
		read_data->buffers->buf_i++;
		read_data->line_i++;
	}
	if (comp_data->ptr_on_possibilities_list->is_reg_file == 1
			&& read_data->buffers->next == NULL)
		space(data, read_data);
	else
		print_after_new_word(data, read_data);
}
