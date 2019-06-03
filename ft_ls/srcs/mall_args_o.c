/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:16:39 by aanger            #+#    #+#             */
/*   Updated: 2018/07/23 22:01:18 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	write_infos_o(struct stat filestat, char *name,
						char options[255], char *dir)
{
	char				buf[2][804];
	char				*date;
	int					i;
	struct passwd		user;

	date = ctime(&filestat.st_mtime);
	if (options['u'] == 1)
		date = ctime(&filestat.st_atime);
	user = *getpwuid(filestat.st_uid);
	i = -1;
	while (++i < 804)
		buf[0][i] = ' ';
	i = 12;
	print_rights(buf, filestat.st_mode, filestat);
	buf_links(buf, filestat);
	buf[0][15] = '\0';
	buf[0][ft_strlen(ft_strcat(buf[0], user.pw_name)) + 2] = '\0';
	buf[0][ft_strlen(buf[0])] = ' ';
	buf_size(buf, filestat, options[10]);
	buf[0][ft_strlen(ft_strncat(buf[0], &date[3], 14) + 1)] = '\0';
	return (write_infos2(buf, name, options, dir));
}

int			malloc_args_o(char *dir, char options[255], t_infos **tab)
{
	struct stat			filestat;
	int					i;
	char				path[BUFF_SIZE2];
	t_infos				*tmp;

	i = 0;
	while (tab[i] != NULL)
	{
		tmp = tab[i];
		ft_bzero(path, BUFF_SIZE2);
		ft_strcpy(path, dir);
		ft_strcat(path, "/");
		ft_strcat(path, tmp->buf);
		lstat(path, &filestat);
		if (tmp->buf[0] != '.' || options['a'] == 1)
			write_infos_o(filestat, tmp->buf, options, dir);
		i++;
	}
	return (0);
}
