/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mall_args_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:15:04 by aanger            #+#    #+#             */
/*   Updated: 2018/08/15 15:14:41 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	int	mall_args_c(char **order, int j)
{
	struct stat	filestat1;
	struct stat	filestat2;
	char		*swap;
	int			i;

	i = -1;
	while (++i < j)
	{
		lstat(order[i], &filestat1);
		lstat(order[i + 1], &filestat2);
		if (filestat1.st_ctime < filestat2.st_ctime)
		{
			swap = order[i];
			order[i] = order[i + 1];
			order[i + 1] = swap;
			i = -1;
		}
	}
	return (0);
}

int			mall_args_u(char **order, int j, char options[255])
{
	struct stat	filestat1;
	struct stat	filestat2;
	char		*swap;
	int			i;

	i = -1;
	if (options['c'] == 1)
		return (mall_args_c(order, j));
	else
		while (++i < j)
		{
			lstat(order[i], &filestat1);
			lstat(order[i + 1], &filestat2);
			if (filestat1.st_atime < filestat2.st_atime)
			{
				swap = order[i];
				order[i] = order[i + 1];
				order[i + 1] = swap;
				i = -1;
			}
		}
	return (0);
}
