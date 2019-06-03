/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slink.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:16:45 by aanger            #+#    #+#             */
/*   Updated: 2018/08/16 13:59:01 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_rights_slink(char buf[2][804], long long rights)
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
		if (i > 2)
			rights /= 8;
		else
			break ;
	}
	buf[0][0] = 'l';
}

static void	buf_links_slink(char buf[2][804], struct stat filestat)
{
	int		temp;
	int		i;

	i = 13;
	temp = filestat.st_nlink;
	while (temp > 0)
	{
		buf[0][i] = temp % 10 + 48;
		temp /= 10;
		i--;
	}
}

static int	write_infos_slink(struct stat filestat, struct group group,
		char *name, int maxsizedigits)
{
	char				buf[2][804];
	char				*date;
	int					i;
	struct passwd		user;

	date = ctime(&filestat.st_mtime);
	user = *getpwuid(filestat.st_uid);
	i = -1;
	while (++i < 804)
		buf[0][i] = ' ';
	i = 12;
	print_rights_slink(buf, filestat.st_mode);
	buf_links_slink(buf, filestat);
	buf[0][15] = '\0';
	buf[0][ft_strlen(ft_strcat(buf[0], user.pw_name)) + 2] = '\0';
	buf[0][ft_strlen(buf[0])] = ' ';
	buf[0][ft_strlen(ft_strcat(buf[0], group.gr_name)) + 2] = '\0';
	buf[0][ft_strlen(buf[0])] = ' ';
	buf_size(buf, filestat, maxsizedigits);
	buf[0][ft_strlen(ft_strncat(buf[0], &date[3], 14) + 1)] = '\0';
	buf[0][ft_strlen(buf[0])] = ' ';
	ft_strcat(buf[0], name);
	ft_strcat(buf[0], "\n");
	write(1, buf[0], ft_strlen(buf[0]));
	return (1);
}

int			slink(char *dir, char maxsizedigits)
{
	struct stat		filestat;
	struct group	group;
	char			buffer[BUFF_SIZE2];
	int				readl;
	char			cpydir[BUFF_SIZE2];

	readl = readlink(dir, buffer, BUFF_SIZE2);
	buffer[readl] = '\0';
	ft_strcpy(cpydir, dir);
	ft_strcat(cpydir, " -> ");
	ft_strcat(cpydir, buffer);
	lstat(dir, &filestat);
	maxsizedigits = ft_nbrlen(filestat.st_size);
	group = *getgrgid(filestat.st_gid);
	write_infos_slink(filestat, group, cpydir, maxsizedigits);
	return (1);
}
