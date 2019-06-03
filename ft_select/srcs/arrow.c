/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:39:37 by aanger            #+#    #+#             */
/*   Updated: 2018/10/16 22:24:33 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	right_arrow(t_data *data)
{
	if (data->one_col == 1)
		return ;
	if (data->breakout_col == 0)
	{
		if (data->curs_po + (data->used_lines + 1) < data->args_nbr)
		{
			data->curs_po += (data->used_lines + 1);
			data->col_curs_po--;
		}
	}
	else
	{
		if (data->col_curs_po < data->args_by_line - 1
		&& data->curs_po + (data->avail_lines) < data->args_nbr)
		{
			data->curs_po += (data->avail_lines);
			return ;
		}
		if (data->decal < data->max_decal
		&& data->curs_po + (data->avail_lines) < data->args_nbr)
		{
			data->curs_po += (data->avail_lines);
			data->decal++;
		}
	}
}

static void	left_arrow(t_data *data)
{
	if (data->one_col == 1)
		return ;
	if (data->breakout_col == 0)
	{
		if (data->col_curs_po > 0)
		{
			data->curs_po -= (data->used_lines + 1);
			data->col_curs_po--;
		}
	}
	else
	{
		if (data->col_curs_po > 0)
		{
			data->curs_po -= (data->avail_lines);
			return ;
		}
		if (data->decal > 0)
		{
			data->decal--;
			data->curs_po -= (data->avail_lines);
		}
	}
}

static void	up_arrow(t_data *data)
{
	if (data->curs_po == 0)
	{
		data->curs_po = data->args_nbr - 1;
		data->decal = data->max_decal;
	}
	else
	{
		if (data->used_lines != 0 && data->curs_po % data->used_lines == 0)
		{
			if (data->breakout_col == 1 && data->col_curs_po == 0)
				data->decal--;
			else
				data->col_curs_po--;
		}
		data->curs_po--;
	}
}

void		down_arrow(t_data *data)
{
	if (data->curs_po == data->args_nbr - 1)
	{
		data->curs_po = 0;
		data->decal = 0;
	}
	else
	{
		data->curs_po++;
		if (data->used_lines != 0 && data->curs_po % data->used_lines == 0)
		{
			if (data->breakout_col == 1
			&& data->col_curs_po == data->args_by_line - 1)
				data->decal++;
			else
				data->col_curs_po++;
		}
	}
}

void		arrow(t_data *data, char buffer[4])
{
	if (buffer[2] == 'A')
		up_arrow(data);
	else if (buffer[2] == 'B')
		down_arrow(data);
	else if (buffer[2] == 'C')
		right_arrow(data);
	else if (buffer[2] == 'D')
		left_arrow(data);
	ft_bzero(data->dyn_sr, 100);
}
