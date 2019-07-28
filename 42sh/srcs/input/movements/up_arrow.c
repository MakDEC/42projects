/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_arrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:03:41 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:13 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "reader.h"
#include "libft.h"
#include <term.h>

static void			copy_history_loop(t_reader *read_data, t_bufstock *begin)
{
	while (begin != NULL)
	{
		if (!(read_data->buffers->next =
					(t_bufstock*)malloc(sizeof(t_bufstock))))
			exit(-1);
		read_data->buffers->next->previous = read_data->buffers;
		read_data->buffers = read_data->buffers->next;
		if (!(read_data->buffers->buffer = (char*)malloc(sizeof(char) * 512)))
			exit(-1);
		read_data->buffers->line = begin->line;
		ft_bzero(read_data->buffers->buffer, 512);
		ft_strcat(read_data->buffers->buffer, begin->buffer);
		read_data->buffers->buf_i = ft_strlen(read_data->buffers->buffer);
		read_data->line_i += read_data->buffers->buf_i;
		read_data->buffers->is_com = begin->is_com;
		read_data->buffers->next = NULL;
		begin = begin->next;
	}
}

void				copy_history(t_reader *read_data, t_bufstock *begin)
{
	if (!(read_data->buffers = (t_bufstock*)malloc(sizeof(t_bufstock))))
		exit(-1);
	read_data->begin = read_data->buffers;
	if (!(read_data->buffers->buffer = (char*)malloc(sizeof(char) * 512)))
		exit(-1);
	ft_bzero(read_data->buffers->buffer, 512);
	read_data->buffers->line = begin->line;
	ft_strcat(read_data->buffers->buffer, begin->buffer);
	read_data->buffers->buf_i = ft_strlen(read_data->buffers->buffer);
	read_data->line_i = read_data->buffers->buf_i;
	read_data->buffers->is_com = begin->is_com;
	read_data->buffers->previous = NULL;
	read_data->buffers->next = NULL;
	begin = begin->next;
	copy_history_loop(read_data, begin);
}

void				reprint_total(t_data *data, t_reader *read_data,
		t_bufstock *begin)
{
	tputs(tgoto(data->termcaps->absoluth_cursor_replace,
				read_data->initiale_cursor_position[1],
				read_data->initiale_cursor_position[0]), 1, reception);
	tputs(data->termcaps->clear_down, 1, reception);
	while (begin != NULL)
	{
		ft_putstr(begin->buffer);
		begin = begin->next;
	}
}

static void			create_temp(t_data *data, t_reader *read_data)
{
	if (!(read_data->temp = (t_temp*)malloc(sizeof(t_temp))))
		exit(-1);
	read_data->temp->buffers = read_data->buffers;
	read_data->temp->begin = read_data->begin;
	read_data->temp->i = read_data->line_i;
	read_data->buffers = NULL;
	read_data->begin = NULL;
	copy_history(read_data, read_data->temp_his->buffers);
	reprint_total(data, read_data, read_data->begin);
}

void				up_arrow(t_data *data, t_reader *read_data)
{
	if (read_data->temp_his == NULL)
	{
		write(1, "\a", 1);
		return ;
	}
	if (read_data->temp_his->nbr == 1 && read_data->temp != NULL)
	{
		write(1, "\a", 1);
		return ;
	}
	if (read_data->temp == NULL)
		return (create_temp(data, read_data));
	free_bufstock(read_data->begin);
	read_data->buffers = NULL;
	read_data->begin = NULL;
	read_data->temp_his = read_data->temp_his->next;
	copy_history(read_data, read_data->temp_his->buffers);
	reprint_total(data, read_data, read_data->begin);
}
