/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 02:01:06 by aanger            #+#    #+#             */
/*   Updated: 2018/10/16 23:28:14 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/ioctl.h>

void			set_decal(t_data *data)
{
	int		temp;

	temp = data->args_by_line * data->avail_lines;
	data->max_decal = 0;
	while (temp < data->args_nbr)
	{
		temp += data->avail_lines;
		data->max_decal++;
	}
	data->decal = 0;
	temp = data->args_by_line * data->avail_lines;
	while (temp <= data->curs_po)
	{
		temp += data->avail_lines;
		data->decal++;
	}
}

static void		layout(t_data *data)
{
	data->breakout_col = 0;
	if (data->len_needed > data->avail_col)
	{
		data->wait = 1;
		return ;
	}
	data->wait = 0;
	if (data->args_nbr < data->avail_lines)
	{
		data->one_col = 1;
		return ;
	}
	data->one_col = 0;
	data->args_by_line = data->avail_col / data->len_needed;
	data->used_lines = data->args_nbr / data->args_by_line;
	if (data->args_nbr < data->avail_lines * data->args_by_line)
		data->breakout_col = 0;
	else
	{
		data->breakout_col = 1;
		data->used_lines = data->avail_lines;
	}
	set_decal(data);
}

static void		set_lines_cols(t_data *data)
{
	struct winsize	ws;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		exit(-1);
	data->total_lines = ws.ws_row;
	data->avail_lines = ws.ws_row - data->initiale_cur_po + 1;
	data->avail_col = ws.ws_col;
}

static void		set_len_needed(t_data *data)
{
	int				len_needed;

	len_needed = data->max_len;
	len_needed++;
	while (len_needed % 8 != 0)
		len_needed++;
	data->len_needed = len_needed;
}

void			set_dynamic_vars(t_data *data)
{
	t_args_list		*temp;

	temp = data->args_list;
	data->max_len = 0;
	while (temp != NULL)
	{
		if (ft_strlen(temp->arg) > data->max_len)
			data->max_len = ft_strlen(temp->arg);
		temp = temp->next;
	}
	set_len_needed(data);
	set_lines_cols(data);
	layout(data);
}
