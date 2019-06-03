/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 02:24:04 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 22:14:44 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_instructions	*init_ins(void)
{
	t_instructions	*ins;

	init_terminal_data();
	if (!(ins = (t_instructions*)malloc(sizeof(t_instructions))))
		exit(-1);
	if ((ins->saved_cursor = tgetstr("sc", NULL)) == NULL)
		exit(-1);
	tputs(ins->saved_cursor, 0, reception);
	if ((ins->restor_cursor = tgetstr("rc", NULL)) == NULL)
		exit(-1);
	if ((ins->clear_down = tgetstr("cd", NULL)) == NULL)
		exit(-1);
	if ((ins->curs_down = tgetstr("do", NULL)) == NULL)
		exit(-1);
	if ((ins->curs_up = tgetstr("up", NULL)) == NULL)
		exit(-1);
	if ((ins->curs_ri = tgetstr("nd", NULL)) == NULL)
		exit(-1);
	if ((ins->curs_lef = tgetstr("le", NULL)) == NULL)
		exit(-1);
	if ((ins->curs_upper_left = tgetstr("ho", NULL)) == NULL)
		exit(-1);
	return (ins);
}
