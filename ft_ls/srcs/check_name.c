/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 05:26:47 by aanger            #+#    #+#             */
/*   Updated: 2018/08/16 17:55:48 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <string.h>

int		print_error(char *dir)
{
	char		buf[1000];
	char		*dirb;

	if (errno == 0)
		errno = 13;
	dirb = ft_strrchr(dir, '/');
	if (ft_strcmp(dir, dirb) != 0)
		dirb[0] = ' ';
	ft_bzero(buf, 1000);
	ft_strcpy(buf, "ft_ls: ");
	ft_strcat(buf, dirb);
	ft_strcat(buf, ": ");
	ft_strcat(buf, "\0");
	write(1, buf, ft_strlen(buf));
	perror("");
	return (0);
}

int		len_error(char *dir)
{
	char		buf[1000];
	char		*dirb;

	dirb = ft_strrchr(dir, '/');
	if (ft_strcmp(dir, dirb) != 0)
		dirb[0] = ' ';
	ft_bzero(buf, 1000);
	ft_strcpy(buf, "ft_ls: ");
	ft_strcat(buf, dirb);
	ft_strcat(buf, ": ");
	ft_strcat(buf, "\0");
	write(1, buf, ft_strlen(buf));
	write(1, "File name too long\n", 19);
	return (0);
}

int		check_params(char **argv, int argc,
			char valid_arg[2][BUFF_SIZE1][BUFF_SIZE2])
{
	int		i;

	i = 1;
	while (i < argc - 1 && argv[i][0] == '-' && argv[i][1] != '-')
		i++;
	if (i == argc - 1 && argv[i][0] == '-')
	{
		valid_arg[1][0][0] = '.';
		valid_arg[1][0][1] = '\0';
		return (0);
	}
	return (i);
}

void	check_validity(int i[3], char **argv,
			char order[BUFF_SIZE1][BUFF_SIZE2],
				char valid_arg[2][BUFF_SIZE1][BUFF_SIZE2])
{
	struct stat	filestat;

	while (i[0] < i[2] && argv[i[0]][0] == '-' && argv[i[0]][1] != '-')
		i[0]++;
	if (argv[i[0]][1] == '-')
		i[0]++;
	while (i[0] < i[2])
	{
		if (ft_strlen(argv[i[0]]) > 300)
			len_error(argv[i[0]]);
		else if (lstat(argv[i[0]], &filestat) == -1)
			ft_strcpy(order[i[1]++], argv[i[0]]);
		else
		{
			if (S_ISDIR(filestat.st_mode) == 0)
				ft_strcpy(valid_arg[0][i[3]++], argv[i[0]]);
			else if (filestat.st_mode - 16639 > 0)
				ft_strcpy(valid_arg[1][i[4]++], argv[i[0]]);
			else
				ft_strcpy(order[i[1]++], argv[i[0]]);
		}
		i[0]++;
	}
}

int		check_name(char **argv, int argc,
			char valid_arg[2][BUFF_SIZE1][BUFF_SIZE2])
{
	int			i[5];
	char		order[BUFF_SIZE1][BUFF_SIZE2];

	if ((i[0] = check_params(argv, argc, valid_arg)) == 0)
		return (0);
	i[1] = 0;
	i[3] = 0;
	i[4] = 0;
	i[2] = argc;
	check_validity(i, argv, order, valid_arg);
	valid_arg[0][i[3]][0] = '\0';
	order[i[1]][0] = '\0';
	valid_arg[1][i[4]][0] = '\0';
	if (i[1] > 0)
		ascii_order(order, i[1]);
	if (i[3] > 0)
		ascii_order(valid_arg[0], i[3]);
	if (i[4] > 0)
		ascii_order(valid_arg[1], i[4]);
	i[0] = -1;
	while (order[++i[0]][0] != '\0')
		print_error(order[i[0]]);
	if (order[0][0] != '\0')
		return (1);
	return (0);
}
