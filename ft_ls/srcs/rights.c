/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 02:54:20 by aanger            #+#    #+#             */
/*   Updated: 2018/08/11 17:11:42 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		check_file_type(char buf[2][804], struct stat filestat)
{
	if (S_ISBLK(filestat.st_mode) == 1)
		buf[0][0] = 'b';
	if (S_ISCHR(filestat.st_mode) == 1)
		buf[0][0] = 'c';
	if (S_ISDIR(filestat.st_mode) == 1)
		buf[0][0] = 'd';
	if (S_ISSOCK(filestat.st_mode) == 1)
		buf[0][0] = 's';
	if (S_ISFIFO(filestat.st_mode) == 1)
		buf[0][0] = 'p';
}

void		print_rights(char buf[2][804], long long rights, struct stat
							filestat)
{
	int		temp;
	int		i;

	i = -1;
	while (++i < 10)
		buf[0][i] = '-';
	i -= 1;
	while (rights >= 100)
	{
		temp = rights % 8;
		if (temp >= 4 && !((temp -= 4) < 0))
			buf[0][i - 2] = 'r';
		if (temp >= 2 && !((temp -= 2) < 0))
			buf[0][i - 1] = 'w';
		if (temp == 1)
			buf[0][i] = 'x';
		i -= 3;
		rights /= 8;
		if (i <= 2)
			break ;
	}
	stickybit(rights % 8, buf);
	check_file_type(buf, filestat);
}
