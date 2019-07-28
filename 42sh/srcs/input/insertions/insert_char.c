/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 03:24:42 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:10 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_struct.h"
#include "data_struct.h"
#include "reader.h"
#include <unistd.h>
#include "libft.h"

static void			insert_char(t_reader *read_data)
{
	char			temp;
	char			temp2;
	int				i;

	i = read_data->buffers->buf_i;
	temp = read_data->buffers->buffer[i];
	read_data->buffers->buffer[i++] = read_data->input_buf[0];
	while (read_data->buffers->buffer[i] != 0)
	{
		temp2 = read_data->buffers->buffer[i];
		read_data->buffers->buffer[i++] = temp;
		temp = temp2;
	}
	read_data->buffers->buffer[i] = temp;
	read_data->line_i++;
	read_data->buffers->buf_i++;
}

static void			add_in_non_last_string(t_reader *read_data)
{
	read_data->buffers->buffer[read_data->buffers->buf_i] =
		read_data->input_buf[0];
	read_data->buffers->buf_i++;
	read_data->line_i++;
}

static void			add_char_on_end(t_reader *read_data)
{
	read_data->buffers->buffer[read_data->buffers->buf_i] =
		read_data->input_buf[0];
	read_data->buffers->buf_i++;
	read_data->line_i++;
	write(1, &read_data->input_buf[0], 1);
}

static void			check_place_in_buffer(t_reader *read_data)
{
	int				index;

	if (read_data->buffers->buf_i == 510)
	{
		read_data->buffers->next = new_buffers_node(read_data->buffers,
				read_data->buffers->next, read_data->buffers->line, 0);
		read_data->buffers = read_data->buffers->next;
	}
	else if (ft_strlen(read_data->buffers->buffer) == 511)
	{
		read_data->buffers->next = new_buffers_node(read_data->buffers,
				read_data->buffers->next, read_data->buffers->line, 0);
		ft_strcat(read_data->buffers->next->buffer,
				&read_data->buffers->buffer[read_data->buffers->buf_i]);
		index = read_data->buffers->buf_i - 1;
		while (read_data->buffers->buffer[++index] != 0)
			read_data->buffers->buffer[index] = 0;
	}
}

void				add_inline_character(t_data *data, t_reader *read_data)
{
	check_place_in_buffer(read_data);
	if (read_data->buffers->buffer[read_data->buffers->buf_i] == 0)
	{
		if (read_data->buffers->next == NULL)
			return (add_char_on_end(read_data));
		add_in_non_last_string(read_data);
	}
	else
		insert_char(read_data);
	reprint_input(data, read_data);
}
