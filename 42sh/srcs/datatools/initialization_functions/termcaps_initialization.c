/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:16:59 by aanger            #+#    #+#             */
/*   Updated: 2019/07/12 23:49:03 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdlib.h>
#include <term.h>
#include "libft.h"
#include "data_struct.h"

static void		init_terminal_data(void)
{
	char			*term_type;
	int				ret_tgetent;

	term_type = getenv("TERM");
	if (term_type == NULL)
	{
		ft_putstr("Terminal type unspecify\nPlease specify a terminal ");
		ft_putstr("typing 'TERM=<type>' and then 'export'.\n");
		exit(-1);
	}
	ret_tgetent = tgetent(NULL, term_type);
	if (ret_tgetent < 0)
	{
		ft_putstr("Failed while trying acces to the terminal database.\n");
		exit(-1);
	}
	if (ret_tgetent == 0)
	{
		ft_putstr("Terminal type ");
		ft_putstr(term_type);
		ft_putstr("seems not defined\n");
		exit(-1);
	}
}

static void		termcap_initialisation_error(char *buf)
{
	ft_putstr_fd("42sh : ", 2);
	ft_putstr_fd(buf, 2);
	ft_putstr_fd(" termcap is not supported by this terminal, ", 2);
	ft_putstr_fd("please launch with a terminal who support it\n", 2);
	exit(-1);
}

static void		init_termcaps_end(t_termcaps *ins)
{
	if ((ins->scroll_up = tgetstr("sf", NULL)) == NULL)
		termcap_initialisation_error("sf");
	if ((ins->absoluth_cursor_replace = tgetstr("cm", NULL)) == NULL)
		termcap_initialisation_error("cm");
}

t_termcaps		*termcaps_initialization(void)
{
	t_termcaps	*ins;

	init_terminal_data();
	if (!(ins = (t_termcaps *)malloc(sizeof(t_termcaps))))
		exit(-1);
	if ((ins->saving_cursor = tgetstr("sc", NULL)) == NULL)
		termcap_initialisation_error("sc");
	if ((ins->restor_cursor = tgetstr("rc", NULL)) == NULL)
		termcap_initialisation_error("rc");
	if ((ins->clear_down = tgetstr("cd", NULL)) == NULL)
		termcap_initialisation_error("cd");
	if ((ins->curs_down = tgetstr("do", NULL)) == NULL)
		termcap_initialisation_error("do");
	if ((ins->curs_up = tgetstr("up", NULL)) == NULL)
		termcap_initialisation_error("up");
	if ((ins->curs_ri = tgetstr("nd", NULL)) == NULL)
		termcap_initialisation_error("nd");
	if ((ins->curs_lef = tgetstr("le", NULL)) == NULL)
		termcap_initialisation_error("le");
	if ((ins->curs_upper_left = tgetstr("ho", NULL)) == NULL)
		termcap_initialisation_error("ho");
	if ((ins->curs_line_begin = tgetstr("cr", NULL)) == NULL)
		termcap_initialisation_error("cr");
	init_termcaps_end(ins);
	return (ins);
}
