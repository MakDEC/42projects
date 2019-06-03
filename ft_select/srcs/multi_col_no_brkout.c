/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_col_no_brkout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:13:35 by aanger            #+#    #+#             */
/*   Updated: 2018/10/16 20:41:29 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	write_line(t_instructions *ins, t_data *data,
		int *writ_args, int current_line)
{
	int				args_in_line;
	int				cursor_in_line;
	int				i;
	int				current_arg;
	t_args_list		*temp;

	args_in_line = 0;
	cursor_in_line = 0;
	while (writ_args[0] < data->args_nbr && args_in_line < data->args_by_line)
	{
		current_arg = current_line + args_in_line * (data->used_lines + 1);
		i = 0;
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

void	multi_col_nobrout(t_instructions *ins, t_data *data)
{
	int				current_line;
	int				written_args;

	current_line = 0;
	written_args = 0;
	while (current_line <= data->used_lines)
	{
		write_line(ins, data, &written_args, current_line);
		if (written_args < data->args_nbr && current_line < data->used_lines)
			tputs(ins->curs_down, 0, reception);
		current_line++;
	}
	place_cursor(ins, data);
}
