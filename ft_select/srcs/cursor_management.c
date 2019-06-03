/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:20:56 by aanger            #+#    #+#             */
/*   Updated: 2018/10/16 16:56:11 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		one_col_move(t_instructions *ins, t_data *data)
{
	int		i;

	i = 0;
	tputs(ins->restor_cursor, 0, reception);
	while (i++ < data->curs_po)
		tputs(ins->curs_down, 0, reception);
}

void		place_cursor(t_instructions *ins, t_data *data)
{
	int		temp;
	int		line;
	int		col;
	int		to_delete;

	temp = data->curs_po;
	line = 0;
	col = 0;
	tputs(ins->restor_cursor, 0, reception);
	while (temp > data->used_lines)
	{
		temp -= (data->used_lines + 1);
		col++;
	}
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
