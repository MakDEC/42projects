/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 23:27:01 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 01:02:57 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_struct.h"
#include "reader.h"
#include "libft.h"

static void		separate_word(t_reader *read_data)
{
	int		i;

	ft_strcat(read_data->buffers->next->buffer, " ");
	if (read_data->buffers->buffer[read_data->buffers->buf_i] != 0)
	{
		ft_strcat(read_data->buffers->next->buffer,
				&read_data->buffers->buffer[read_data->buffers->buf_i]);
		i = read_data->buffers->buf_i;
		while (read_data->buffers->buffer[i] != 0)
			read_data->buffers->buffer[i++] = 0;
	}
	read_data->buffers = read_data->buffers->next;
}

static void		first_character(t_reader *read_data)
{
	ft_strcat(read_data->buffers->buffer, " ");
	write(1, " ", 1);
	read_data->buffers->buf_i++;
	read_data->line_i++;
}

static void		create_new_buffers_node(t_data *data, t_reader *read_data)
{
	read_data->buffers->next = new_buffers_node(read_data->buffers,
			read_data->buffers->next, read_data->buffers->line, 0);
	if (read_data->buffers->buffer[read_data->buffers->buf_i] != 0)
		separate_word(read_data);
	else
	{
		read_data->buffers = read_data->buffers->next;
		ft_strcat(read_data->buffers->buffer, " ");
		write(1, " ", 1);
		read_data->buffers->buf_i++;
		read_data->line_i++;
		return ;
	}
	read_data->buffers->buf_i++;
	read_data->line_i++;
	reprint_input(data, read_data);
}

void			space(t_data *data, t_reader *read_data)
{
	if (read_data->buffers->buf_i == 0
			&& read_data->buffers->buffer[read_data->buffers->buf_i] == 0
			&& read_data->buffers->next == NULL
			&& read_data->buffers->previous == NULL)
		return (first_character(read_data));
	else if (read_data->buffers->buf_i > 0
			&& read_data->buffers->buffer[read_data->buffers->buf_i - 1] != ' ')
		return (create_new_buffers_node(data, read_data));
	else
		add_inline_character(data, read_data);
}
