/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_part_of_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:48:23 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 15:00:04 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "input_struct.h"
#include "reader.h"
#include "libft.h"
#include <term.h>
#include "intern_select.h"

static void				erase_in_read_data(t_data *data, t_reader *read_data,
		t_select_data *select_data)
{
	t_select_char		*temp;
	int					options;

	options = 0;
	if (select_data->select_begin->next == NULL)
		temp = select_data->select_begin;
	else
	{
		options = 1;
		temp = select_data->select_current_case;
	}
	while (temp != NULL)
	{
		if (options == 1)
			right_arrow(data, read_data);
		backspace(data, read_data);
		temp = temp->previous;
	}
	if (options == 0)
		tputs(data->termcaps->saving_cursor, 1, reception);
}

static int				select_read_loop(t_data *data,
		t_select_data *select_data)
{
	char				read_buffer[7];
	int					ret_read;

	ft_bzero(read_buffer, 7);
	while ((ret_read = read(0, read_buffer, 7)) != -1)
	{
		read_buffer[ret_read] = 0;
		if (ret_read == 3 && read_buffer[0] == 27 && read_buffer[1] == 91)
		{
			if (read_buffer[2] == 67)
				select_right_arrow(data, select_data);
			else if (read_buffer[2] == 68)
				select_left_arrow(data, select_data);
		}
		else if (ret_read == 2 && read_buffer[0] == -61
				&& read_buffer[1] == -89)
			return (1);
		else if (ret_read == 3 && read_buffer[0] == -30
				&& read_buffer[1] == -119 && read_buffer[2] == -120)
			return (2);
		else if (ret_read == 1 && read_buffer[0] == 27)
			return (0);
	}
	return (1);
}

void					select_part_of_input(t_data *data, t_reader *read_data)
{
	t_select_data	*select_data;
	int				end_to_operate;

	if (read_data->begin->buffer[0] == 0
			&& read_data->begin->next == NULL)
	{
		write(1, "\a", 1);
		return ;
	}
	tputs(data->termcaps->saving_cursor, 1, reception);
	select_data = prepare_select_struct(data, read_data);
	write_reverse_char(select_data, 1);
	end_to_operate = select_read_loop(data, select_data);
	if (end_to_operate == 2)
		erase_in_read_data(data, read_data, select_data);
	if (end_to_operate == 0)
		free_select_data(select_data);
	else
		save_and_free_select_data(data, select_data);
	reprint_total(data, read_data, read_data->begin);
	tputs(data->termcaps->restor_cursor, 1, reception);
}
