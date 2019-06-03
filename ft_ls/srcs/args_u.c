/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:15:04 by aanger            #+#    #+#             */
/*   Updated: 2018/08/14 18:21:21 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	int	args_c(char order[BUFF_SIZE1][BUFF_SIZE2], int j)
{
	struct stat	filestat1;
	struct stat	filestat2;
	char		swap[BUFF_SIZE2];
	int			i;

	i = -1;
	while (++i < j)
	{
		lstat(order[i], &filestat1);
		lstat(order[i + 1], &filestat2);
		if (filestat1.st_ctime < filestat2.st_ctime)
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
	return (0);
}

int			args_u(char order[BUFF_SIZE1][BUFF_SIZE2], int j, char options[255])
{
	struct stat	filestat1;
	struct stat	filestat2;
	char		swap[BUFF_SIZE2];
	int			i;

	i = -1;
	if (options['c'] == 1)
		return (args_c(order, j));
	else
		while (++i < j)
		{
			lstat(order[i], &filestat1);
			lstat(order[i + 1], &filestat2);
			if (filestat1.st_atime < filestat2.st_atime)
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
	return (0);
}
