/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_arrow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:12:40 by aanger            #+#    #+#             */
/*   Updated: 2019/03/16 15:23:41 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "reader.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void		set_line_i(t_reader *read_data)
{
	read_data->buffers = read_data->begin;
	read_data->line_i = 0;
	while (read_data->buffers->next != NULL)
	{
		read_data->line_i += ft_strlen(read_data->buffers->buffer);
		read_data->buffers = read_data->buffers->next;
		if (read_data->buffers->previous->line != read_data->buffers->line)
			read_data->line_i = 0;
	}
	read_data->line_i += ft_strlen(read_data->buffers->buffer);
}

static void		restore_temp_in_read_data(t_reader *read_data)
{
	read_data->begin = read_data->temp->begin;
	set_line_i(read_data);
	free(read_data->temp);
	read_data->temp = NULL;
}

void			down_arrow(t_data *data, t_reader *read_data)
{
	if (read_data->temp_his == NULL || read_data->temp == NULL)
	{
		write(1, "\a", 1);
		return ;
	}
	free_bufstock(read_data->begin);
	read_data->buffers = NULL;
	read_data->begin = NULL;
	if (read_data->temp_his->previous == NULL)
		restore_temp_in_read_data(read_data);
	else
	{
		read_data->temp_his = read_data->temp_his->previous;
		copy_history(read_data, read_data->temp_his->buffers);
	}
	reprint_total(data, read_data, read_data->begin);
}
