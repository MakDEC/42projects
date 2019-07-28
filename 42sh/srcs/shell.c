/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:00:34 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:29:44 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
**	POSIX specifications :
**	https://pubs.opengroup.org/onlinepubs/9699919799/
*/

int					main(int argc, char **argv, char **env)
{
	t_data			*data;
	int				exit_status;

	(void)argv;
	if (argc != 1)
		return (ft_putstr("Please launch 42sh without args\n"));
	if (isatty(0) != 1 || isatty(1) != 1 || isatty(2) != 1)
	{
		ft_putstr_fd("It seems that fd 0, fd 1 or fd 2 isn't a tty, ", 2);
		ft_putstr_fd("please launch 42sh in normal conditions\n", 2);
		return (-1);
	}
	data = init_data_struct(env);
	setpgid(0, 0);
	monitor(data);
	exit_status = data->exit_status;
	free_data(data);
	return (exit_status % 255);
}
