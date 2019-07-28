/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 23:34:38 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 01:46:01 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "reader.h"
#include "libft.h"

static void		fill_rslt(char **rslt, t_reader *read_data)
{
	int			size_to_malloc;

	size_to_malloc = 0;
	read_data->buffers = read_data->begin;
	while (read_data->buffers != NULL)
	{
		size_to_malloc += ft_strlen(read_data->buffers->buffer);
		read_data->buffers = read_data->buffers->next;
	}
	size_to_malloc++;
	if (!(rslt[0] = (char*)malloc(sizeof(char) * size_to_malloc)))
		exit(-1);
	ft_bzero(rslt[0], size_to_malloc);
	read_data->buffers = read_data->begin;
	while (read_data->buffers != NULL)
	{
		ft_strcat(rslt[0], read_data->buffers->buffer);
		read_data->buffers = read_data->buffers->next;
	}
}

static int		read_loop(t_data *data, t_reader *read_data)
{
	while (1)
	{
		if (read_data->ret_read > -1)
			read_data->ret_read = read(0, read_data->input_buf, 7);
		if (read_data->ret_read == -1)
			return (-1);
		if (read_data->ret_read >= 0)
			read_data->input_buf[read_data->ret_read] = 0;
		read_input_buf(data, read_data);
		if (read_data->ret_read_buf == 0)
			return (read_data->ret_read_buf);
		ft_bzero(read_data->input_buf, 7);
		read_data->ret_read = 0;
	}
	return (1);
}

static void		clear_read_data(t_reader *read_data)
{
	t_bufstock	*temp;

	if (read_data == NULL)
		return ;
	temp = read_data->begin;
	while (temp != NULL)
	{
		if (temp->buffer != NULL)
			free(temp->buffer);
		read_data->buffers = temp;
		temp = temp->next;
		free(read_data->buffers);
	}
	free(read_data);
}

/*
**		The Line edition return 1 if she hasn't finish,
**		0 if finished and -1 in case of error (sigint on read)
*/


int				reader(t_data *data, char **rslt)
{
	t_reader		*read_data;
	int			ret_read_loop;

	read_data = init_reader_data(data);
	ret_read_loop = read_loop(data, read_data);
	if (ret_read_loop == 0)
	{
		fill_rslt(rslt, read_data);
		stock_history(data, read_data);
	}
	else
		clear_read_data(read_data);
	ft_putchar('\n');
	return (ret_read_loop);
}
