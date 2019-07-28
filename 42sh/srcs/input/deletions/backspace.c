/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:52:44 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:09 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_struct.h"
#include "libft.h"
#include "reader.h"

static void	erase_nonlast_char(t_reader *read_data)
{
	int				i;

	i = read_data->buffers->buf_i;
	while (read_data->buffers->buffer[i] != 0)
	{
		read_data->buffers->buffer[i - 1] = read_data->buffers->buffer[i];
		i++;
	}
	read_data->buffers->buffer[i - 1] = 0;
}

static void	erase_node(t_reader *read_data)
{
	t_bufstock		*temp;

	if (read_data->buffers->buffer[0] != 0)
	{
		if (read_data->buffers->buffer[0] != ' ')
			ft_strcat(read_data->buffers->previous->buffer,
					&read_data->buffers->buffer[0]);
		else
			ft_strcat(read_data->buffers->previous->buffer,
					&read_data->buffers->buffer[1]);
	}
	free(read_data->buffers->buffer);
	read_data->buffers->buffer = NULL;
	read_data->buffers->previous->next = read_data->buffers->next;
	if (read_data->buffers->next != NULL)
		read_data->buffers->next->previous = read_data->buffers->previous;
	temp = read_data->buffers;
	read_data->buffers = read_data->buffers->previous;
	free(temp);
	read_data->buffers->buf_i++;
}

static void	delete_line_feed(t_bufstock *buffers, t_reader *read_data)
{
	read_data->line_i = 0;
	while (buffers->previous != NULL
			&& buffers->line == buffers->previous->line)
		buffers = buffers->previous;
	while (buffers->next->line == buffers->line)
	{
		while (buffers->buffer[buffers->buf_i] != 0)
		{
			buffers->buf_i++;
			read_data->line_i++;
		}
		buffers = buffers->next;
	}
	while (buffers->buffer[buffers->buf_i] != '\n')
	{
		buffers->buf_i++;
		read_data->line_i++;
	}
	buffers->buffer[buffers->buf_i] = 0;
}

static int	delete_line(t_data *data, t_reader *read_data)
{
	t_bufstock		*temp;

	delete_line_feed(read_data->buffers->previous, read_data);
	line_width(data, read_data);
	erase_node(read_data);
	read_data->buffers->buf_i--;
	temp = read_data->buffers->next;
	while (temp != NULL)
	{
		temp->line -= 1;
		temp = temp->next;
	}
	return (0);
}

int			backspace(t_data *data, t_reader *read_data)
{
	if (read_data->line_i == 0 && read_data->buffers->previous == NULL)
	{
		ring_bell();
		return (1);
	}
	else if ((read_data->line_i == 0)
			&& read_data->buffers->previous != NULL)
		return (delete_line(data, read_data));
	else if (read_data->buffers->buf_i == 1
			&& read_data->buffers->buffer[0] == ' '
			&& read_data->buffers->previous != NULL)
		erase_node(read_data);
	else if (read_data->buffers->buffer[read_data->buffers->buf_i] != 0)
		erase_nonlast_char(read_data);
	else
		read_data->buffers->buffer[read_data->buffers->buf_i - 1] = 0;
	read_data->buffers->buf_i--;
	read_data->line_i--;
	return (0);
}
