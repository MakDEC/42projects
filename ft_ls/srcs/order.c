/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:50:11 by aanger            #+#    #+#             */
/*   Updated: 2018/08/14 18:20:20 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ascii_order(char order[BUFF_SIZE1][BUFF_SIZE2], int j)
{
	char			swap[BUFF_SIZE2];
	int				i;

	i = -1;
	if (j == 1)
		return ;
	while (++i < j - 1)
		if (order[i + 1] && ft_strcmp(order[i], order[i + 1]) > 0)
		{
			ft_bzero(swap, BUFF_SIZE2);
			ft_strcpy(swap, order[i]);
			ft_bzero(order[i], BUFF_SIZE2);
			ft_strcpy(order[i], order[i + 1]);
			ft_bzero(order[i + 1], BUFF_SIZE2);
			ft_strcpy(order[i + 1], swap);
			i = -1;
		}
}

int			exit_err(char *dir, char order[BUFF_SIZE1][BUFF_SIZE2])
{
	struct stat		filestat;

	if (lstat(dir, &filestat) != 0)
		print_error(dir);
	else
		ft_strcpy(order[0], dir);
	return (0);
}

static int	stock_names(char *dir, char order[BUFF_SIZE1][BUFF_SIZE2],
					char options[255])
{
	DIR				*rep;
	struct dirent	*readfile;
	int				i;

	if ((rep = opendir(dir)) == NULL)
		return (exit_err(dir, order));
	i = 0;
	while ((readfile = readdir(rep)) != NULL)
	{
		if (options['a'] == 1 || readfile->d_name[0] != '.')
		{
			if (i == BUFF_SIZE1 || ft_strlen(readfile->d_name) > 299)
			{
				while ((readfile = readdir(rep)) != NULL)
					i++;
				closedir(rep);
				return (i);
			}
			ft_strcpy(order[i], readfile->d_name);
			i++;
		}
	}
	order[i][0] = '\0';
	closedir(rep);
	return (i - 1);
}

int			orderer(char dir[300], char order[BUFF_SIZE1][BUFF_SIZE2],
			char options[255])
{
	int				i;
	int				j;
	t_infos			**tab;

	i = 0;
	j = 0;
	i = stock_names(dir, order, options);
	if (i > 300 || options['f'] == 1 || options['t'] == 1 || options['r'] == 1)
	{
		options[15] = 1;
		tab = malloc_ascii_order(dir, options);
		if (options['l'] == 0 && options['o'] == 0)
			return (malloc_args_null(options, tab));
		options[10] = write_total(dir, options);
		if (options['o'] == 0)
			return (malloc_args_la(dir, options, tab));
		return (malloc_args_o(dir, options, tab));
	}
	if (i == 0)
		return (0);
	j = i + 1;
	if (options['f'] == 0)
		ascii_order(order, j);
	return (1);
}
