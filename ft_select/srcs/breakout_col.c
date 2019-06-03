/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breakout_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:13:35 by aanger            #+#    #+#             */
/*   Updated: 2018/10/16 20:41:44 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		place_cursor_brk(t_instructions *ins, t_data *data)
{
	int		temp;
	int		line;
	int		col;
	int		to_delete;

	temp = data->curs_po;
	temp -= (data->avail_lines * data->decal);
	line = 0;
	col = 0;
	tputs(ins->restor_cursor, 0, reception);
	while (temp >= data->avail_lines && (col++) != -1)
		temp -= (data->avail_lines);
	while (temp-- > 0)
		line++;
	to_delete = col - 1;
	while (line-- > 0)
		tputs(ins->curs_down, 0, reception);
	data->col_curs_po = col;
	col *= data->len_needed;
	if (to_delete > 0)
		col -= to_delete;
	while (col-- > 0)
		tputs(ins->curs_ri, 0, reception);
}

static void		write_line_brk(t_instructions *ins, t_data *data,
				int *writ_args, int current_line)
{
	int				args_in_line;
	int				cursor_in_line;
	int				i;
	int				current_arg;
	t_args_list		*temp;

	args_in_line = 0;
	cursor_in_line = 0;
	while (args_in_line < data->args_by_line && (i = 0) != -1)
	{
		current_arg = current_line + (args_in_line * (data->avail_lines))
		+ (data->decal * data->avail_lines);
		temp = data->args_list;
		while (temp != NULL && i++ < current_arg)
			temp = temp->next;
		if (temp != NULL)
		{
			set_color(temp, data, i - 1);
			cursor_in_line += ft_strlen(temp->arg);
			writ_args[0]++;
		}
		while (cursor_in_line++ % data->len_needed != 0)
			tputs(ins->curs_ri, 0, reception);
		args_in_line++;
	}
}

void			breakout_print(t_instructions *ins, t_data *data)
{
	int				current_line;
	int				written_args;

	current_line = 0;
	written_args = 0;
	while (current_line < data->avail_lines)
	{
		write_line_brk(ins, data, &written_args, current_line);
		if (current_line < data->avail_lines - 1)
			tputs(ins->curs_down, 0, reception);
		current_line++;
	}
	place_cursor_brk(ins, data);
}
