/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 01:56:12 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 21:51:39 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <sys/ioctl.h>

t_data			*g_data;
t_instructions	*g_ins;
int				g_resized;

void		wind_resized(int sigwinch)
{
	(void)sigwinch;
	tputs(g_ins->curs_upper_left, 0, reception);
	tputs(g_ins->saved_cursor, 0, reception);
	tputs(g_ins->clear_down, 0, reception);
	g_data->initiale_cur_po = beginning_line();
	set_dynamic_vars(g_data);
	print_list(g_ins, g_data);
}

void		process_continue(int sigcont)
{
	struct winsize	ws;

	(void)sigcont;
	prep_term();
	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		exit(-1);
	if (ws.ws_row != g_data->total_lines || ws.ws_col != g_data->avail_col)
	{
		tputs(g_ins->curs_upper_left, 1, reception);
		g_data->initiale_cur_po = 0;
	}
	else
		g_data->initiale_cur_po = beginning_line();
	tputs(g_ins->saved_cursor, 1, reception);
	set_dynamic_vars(g_data);
	print_list(g_ins, g_data);
}

void		process_killed(int sigint)
{
	tcsetattr(0, 0, &g_data->original_term);
	tputs(g_ins->restor_cursor, 0, reception);
	tputs(g_ins->clear_down, 0, reception);
	write(0, "ft_select killed by signal\nInitial terminal configuration", 58);
	write(0, " successfully restored\n", 23);
	exit(sigint);
}

void		init_sig(void)
{
	signal(SIGWINCH, wind_resized);
	signal(SIGCONT, process_continue);
	signal(SIGINT, process_killed);
	signal(SIGQUIT, process_killed);
}
