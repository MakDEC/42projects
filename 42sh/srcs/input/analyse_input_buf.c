/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_input_buf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:41:22 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 01:00:44 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "reader.h"

static void		read_input_buf2(t_data *data, t_reader *read_data)
{
	if (read_data->ret_read == 1 && read_data->input_buf[0] == 127)
	{
		if (backspace(data, read_data) == 0)
			reprint_after_backspace(data, read_data);
	}
	else if (read_data->ret_read == 1 && read_data->input_buf[0] == 32)
		space(data, read_data);
	else if (read_data->ret_read == 1
			&& ft_isprint(read_data->input_buf[0]) == 1)
		add_inline_character(data, read_data);
	else if (read_data->ret_read == 1 && read_data->input_buf[0] == 9)
		completion(data, read_data);
	else if (read_data->ret_read == 2 && read_data->input_buf[0] == -61
			&& read_data->input_buf[1] == -97)
		select_part_of_input(data, read_data);
	else if (read_data->ret_read == 3 && read_data->input_buf[0] == -30
			&& read_data->input_buf[1] == -120
			&& read_data->input_buf[2] == -102)
		paste_clipboard(data, read_data);
}

static void		is_valid_control_d(t_data *data, t_reader *read_data)
{
	if (ft_strlen(read_data->begin->buffer) == 0)
	{
		read_data->ret_read_buf = 0;
		data->exit_status = data->last_cmd_status;
		ft_putchar('\n');
	}
	else
		read_data->ret_read_buf = 1;
}

void			read_input_buf(t_data *data, t_reader *read_data)
{
	if (read_data->ret_read == 3 && read_data->input_buf[2] >= 65
			&& read_data->input_buf[2] <= 68)
		return (arrow(data, read_data));
	if (read_data->ret_read == 3 && read_data->input_buf[2] == 72)
		return (back_to_begin(data, read_data));
	if (read_data->ret_read == 3 && read_data->input_buf[2] == 70)
		return (cursor_to_end(data, read_data));
	if (read_data->ret_read == 1 && (read_data->input_buf[0] == 10
				|| read_data->input_buf[0] == 4))
	{
		read_data->ret_read_buf = 0;
		if (read_data->input_buf[0] == 4)
			is_valid_control_d(data, read_data);
		return ;
	}
	if (read_data->ret_read == 4 && read_data->input_buf[0] == 27
			&& read_data->input_buf[1] == 27 && read_data->input_buf[2] == 91
			&& (read_data->input_buf[3] >= 65 || read_data->input_buf[3] <= 68))
		return (alt_arrow(data, read_data));
	read_input_buf2(data, read_data);
}
