/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:46:46 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 01:01:19 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "input_struct.h"
#include "reader.h"
#include <stdlib.h>

static void	create_history(t_data *data, t_reader *read_data)
{
	if (!(data->history = (t_history*)malloc(sizeof(t_history))))
		exit(-1);
	data->history->next = NULL;
	data->history->previous = NULL;
	data->history->nbr = 1;
	data->history->buffers = read_data->begin;
	if (read_data->temp != NULL)
	{
		free_bufstock(read_data->temp->begin);
		free(read_data->temp);
	}
	free(read_data);
}

static void	clear_without_save(t_reader *read_data)
{
	free(read_data->begin->buffer);
	free(read_data->begin);
	free(read_data);
}

static int	check_non_empty(t_reader *read_data)
{
	int		i;

	read_data->buffers = read_data->begin;
	while (read_data->buffers != NULL)
	{
		i = -1;
		while (read_data->buffers->buffer[++i] != 0)
		{
			if (read_data->buffers->buffer[i] != ' '
					&& read_data->buffers->buffer[i] != '\t')
				return (1);
		}
		read_data->buffers = read_data->buffers->next;
	}
	return (0);
}

void		stock_history(t_data *data, t_reader *read_data)
{
	t_history	*temp;

	if (check_non_empty(read_data) == 0)
		return (clear_without_save(read_data));
	if (data->history == NULL)
		return (create_history(data, read_data));
	if (!(temp = (t_history*)malloc(sizeof(t_history))))
		exit(-1);
	temp->buffers = read_data->begin;
	temp->previous = NULL;
	temp->next = data->history;
	temp->nbr = temp->next->nbr + 1;
	data->history->previous = temp;
	data->history = temp;
	if (read_data->temp != NULL)
	{
		free_bufstock(read_data->temp->begin);
		free(read_data->temp);
	}
	free(read_data);
}
