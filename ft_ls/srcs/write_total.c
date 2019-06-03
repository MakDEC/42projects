/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:16:39 by aanger            #+#    #+#             */
/*   Updated: 2018/07/24 15:37:04 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		afficher_total(char buffer[BUFF_SIZE2], int blocks)
{
	char	*buf;

	ft_bzero(buffer, BUFF_SIZE2);
	ft_strcat(buffer, "total ");
	buf = ft_itoa(blocks);
	ft_strcat(buffer, buf);
	free(buf);
	ft_strcat(buffer, "\n");
	ft_putstr(buffer);
}

static int		read_dir(DIR *cpyrep, char *dir,
					char options[255])
{
	struct dirent	*readfile;
	char			buffer[BUFF_SIZE2];
	int				blocks;
	int				maxsize;
	struct stat		filestat;

	blocks = 0;
	maxsize = 0;
	while ((readfile = readdir(cpyrep)) != NULL)
	{
		ft_bzero(buffer, BUFF_SIZE2);
		ft_strcat(buffer, dir);
		ft_strcat(buffer, "/");
		ft_strcat(buffer, readfile->d_name);
		lstat(buffer, &filestat);
		if (readfile->d_name[0] != '.' || options['a'] == 1)
			blocks += filestat.st_blocks;
		if (ft_nbrlen(filestat.st_size) > maxsize)
			maxsize = ft_nbrlen(filestat.st_size);
	}
	afficher_total(buffer, blocks);
	return (maxsize);
}

char			write_total(char *dir, char options[255])
{
	DIR					*cpyrep;
	int					maxsize;

	if ((cpyrep = opendir(dir)) == NULL)
		return (0);
	maxsize = read_dir(cpyrep, dir, options);
	closedir(cpyrep);
	return (maxsize);
}
