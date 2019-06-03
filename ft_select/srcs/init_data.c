/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prerequisite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:03:10 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 18:52:37 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <termios.h>
#include "ft_select.h"

void			prep_term(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) != 0)
		exit(-1);
	term.c_lflag &= ~(-ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= (ISIG);
	tcsetattr(0, 0, &term);
}

int				beginning_line(void)
{
	char	buf[4];
	int		line;

	write(0, "\033[6n", 4);
	read(0, buf, 4);
	line = ft_atoi(&buf[2]);
	return (line);
}

void			copy_args(t_args_list *temp, char **argv, int argc)
{
	int			i;

	i = 1;
	temp->arg = argv[i];
	temp->select = 0;
	temp->next = NULL;
	while (++i < argc)
	{
		if (!(temp->next = (t_args_list*)malloc(sizeof(t_args_list))))
			exit(-1);
		temp = temp->next;
		temp->arg = argv[i];
		temp->select = 0;
		temp->next = NULL;
	}
}

t_data			*init_data(int argc, char **argv, struct termios original_term)
{
	t_data			*data;
	t_args_list		*temp;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		exit(-1);
	if (!(data->args_list = (t_args_list*)malloc(sizeof(t_args_list))))
		exit(-1);
	data->original_term = original_term;
	temp = data->args_list;
	copy_args(temp, argv, argc);
	data->initiale_cur_po = beginning_line();
	data->args_nbr = argc - 1;
	data->curs_po = 0;
	data->col_curs_po = 0;
	data->decal = 0;
	ft_bzero(data->dyn_sr, 100);
	set_dynamic_vars(data);
	return (data);
}

void			init_terminal_data(void)
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
