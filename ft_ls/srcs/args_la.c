/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_la.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:16:39 by aanger            #+#    #+#             */
/*   Updated: 2018/08/16 17:20:50 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			buf_size(char buf[2][804], struct stat filestat,
					char maxsizedigits)
{
	int		i;
	long	temp;

	i = 40;
	buf[0][i] = ' ';
	temp = filestat.st_size;
	i += maxsizedigits - 1;
	buf[0][i + 1] = '\0';
	if (temp == 0)
		return (buf[0][i] = '0');
	temp *= 10;
	while (temp > 0 && (temp = temp / 10))
		buf[0][i--] = temp % 10 + 48;
	return (0);
}

int			write_infos2(char buf[2][804], char *name,
				char options[255], char *dir)
{
	buf[0][ft_strlen(buf[0])] = ' ';
	if (ft_strcmp(name, "sgoinfre") != 0 &&
			ft_strcmp(name, "sgoinfre_old") != 0)
		return (namer(buf, name, options, dir));
	ft_strcat(buf[0], name);
	ft_strcat(buf[0], "\n");
	return (write(1, buf[0], ft_strlen(buf[0])));
}

static void	user_et_groupe(char buf[2][804], struct passwd user,
			struct group group, char options[255])
{
	if (user.pw_name != NULL)
	{
		buf[0][ft_strlen(ft_strcat(buf[0], user.pw_name)) + 2] = '\0';
		buf[0][ft_strlen(buf[0])] = ' ';
		if (options[10] > 0)
			buf[0][ft_strlen(ft_strcat(buf[0], group.gr_name)) +
				options[10]] = '\0';
		else
			buf[0][ft_strlen(ft_strcat(buf[0], group.gr_name)) + 5] = '\0';
	}
	else
	{
		buf[0][ft_strlen(ft_strcat(buf[0], "4389 ")) + 1] = '\0';
		buf[0][ft_strlen(buf[0])] = ' ';
		buf[0][ft_strlen(ft_strcat(buf[0], group.gr_name)) + 5] = '\0';
	}
	while (ft_strlen(buf[0]) < 40)
		ft_strcat(buf[0], " ");
}

int			write_infos(struct stat filestat, char *name,
						char options[255], char *dir)
{
	char				buf[2][804];
	char				*date;
	int					i;
	struct passwd		user;
	struct group		group;

	user.pw_name = NULL;
	group = *getgrgid(filestat.st_gid);
	if (ft_strcmp(group.gr_name, "_lpoperator") != 0)
		user = *getpwuid(filestat.st_uid);
	date = set_date(filestat, options);
	i = -1;
	while (++i < 804)
		buf[0][i] = ' ';
	i = 12;
	print_rights(buf, filestat.st_mode, filestat);
	buf_links(buf, filestat);
	buf[0][15] = '\0';
	user_et_groupe(buf, user, group, options);
	buf_size(buf, filestat, options[10] > 0 ? options[10] : 4);
	buf[0][ft_strlen(ft_strncat(buf[0], &date[3], 14) + 1)] = '\0';
	free(date);
	return (write_infos2(buf, name, options, dir));
}

int			args_la(char *dir, char options[255],
					char order[BUFF_SIZE1][BUFF_SIZE2])
{
	struct stat			filestat;
	int					i;
	char				path[BUFF_SIZE2];

	i = 0;
	while (order[i][0])
	{
		ft_bzero(path, BUFF_SIZE2);
		ft_strcpy(path, dir);
		ft_strcat(path, "/");
		ft_strcat(path, order[i]);
		if (lstat(path, &filestat) < 0)
			lstat(dir, &filestat);
		if ((ft_strcmp(dir, "/dev") == 0 || ft_strcmp(dir, "/dev/") == 0) && (
				order[i][0] != '.' && options['a'] == 0))
			dev_dir(filestat, order[i], options);
		else if ((order[i][0] != '.' || options['a'] == 1))
			write_infos(filestat, order[i], options, dir);
		i++;
	}
	return (0);
}
