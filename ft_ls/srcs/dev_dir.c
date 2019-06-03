/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_la.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:16:39 by aanger            #+#    #+#             */
/*   Updated: 2018/08/11 18:10:25 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		buf_minor(char buf[2][804], int minor)
{
	int		i;

	i = 39;
	if (minor == 0)
		buf[0][39] = '0';
	else
		while (minor > 0)
		{
			buf[0][i] = minor % 10 + 48;
			minor /= 10;
			i--;
		}
	buf[0][40] = '\0';
}

static void		buf_major_minor(char buf[2][804], struct stat filestat)
{
	int		i;
	int		major;
	int		minor;

	i = 34;
	buf[0][ft_strlen(buf[0])] = ' ';
	major = major(filestat.st_rdev);
	minor = minor(filestat.st_rdev);
	if (major == 0)
		buf[0][34] = '0';
	else
		while (major > 0)
		{
			buf[0][i] = major % 10 + 48;
			major /= 10;
			i--;
		}
	buf[0][35] = ',';
	buf_minor(buf, minor);
}

static int		write_infos2_dev(char buf[2][804], char *name)
{
	char	buffer[BUFF_SIZE2];
	char	tmp[500];

	ft_bzero(tmp, 500);
	ft_bzero(buffer, BUFF_SIZE2);
	ft_strcat(tmp, "/dev/");
	ft_strcat(tmp, name);
	buf[0][ft_strlen(buf[0])] = ' ';
	if (readlink(tmp, buffer, BUFF_SIZE2) == -1)
		ft_strcat(buf[0], name);
	else
	{
		ft_strcat(buf[0], name);
		ft_strcat(buf[0], " -> ");
		ft_strcat(buf[0], buffer);
	}
	ft_strcat(buf[0], "\n");
	return (write(1, buf[0], ft_strlen(buf[0])));
}

static void		verif_dir(struct stat filestat, char *name, char buf[2][804])
{
	if (ft_strcmp(name, "fd") != 0 && ft_strcmp(name, "stderr") != 0 &&
	ft_strcmp(name, "stdin") != 0 && ft_strcmp(name, "stdout") != 0)
		buf_major_minor(buf, filestat);
	else
		ft_strcat(buf[0], "              0");
}

int				dev_dir(struct stat filestat, char *name, char options[255])
{
	char				buf[2][804];
	char				*date;
	int					i;
	struct passwd		user;
	struct group		group;

	group = *getgrgid(filestat.st_gid);
	date = set_date(filestat, options);
	user = *getpwuid(filestat.st_uid);
	i = -1;
	while (++i < 804)
		buf[0][i] = ' ';
	i = 12;
	print_rights(buf, filestat.st_mode, filestat);
	buf_links(buf, filestat);
	buf[0][15] = '\0';
	buf[0][ft_strlen(ft_strcat(buf[0], user.pw_name)) + 1] = '\0';
	buf[0][ft_strlen(buf[0])] = ' ';
	ft_strcat(buf[0], group.gr_name);
	while (ft_strlen(buf[0]) < 25)
		ft_strcat(buf[0], "\t");
	verif_dir(filestat, name, buf);
	buf[0][ft_strlen(ft_strncat(buf[0], &date[3], 14) + 1)] = '\0';
	write_infos2_dev(buf, name);
	return (0);
}
