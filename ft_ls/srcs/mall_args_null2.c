/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mall_args_null2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 00:48:18 by aanger            #+#    #+#             */
/*   Updated: 2018/07/23 22:00:53 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

static size_t	malloc_max_width(t_infos **tab)
{
	size_t			max;
	int				i;
	t_infos			*tmp;

	max = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		tmp = tab[i];
		if (tmp->size > max)
			max = tmp->size;
		i++;
	}
	return (max);
}

size_t			malloc_lines(t_infos **tab, size_t max[4][1])
{
	int				i;

	i = 0;
	if ((max[0][0] = malloc_max_width(tab)) == 0)
		return (-1);
	if (max[0][0] % 8 == 0)
		max[0][0] += 8;
	while ((max[0][0] % 8) != 0)
		max[0][0]++;
	while (tab[i] != NULL)
		i++;
	max[1][0] = (screenwidth() / max[0][0]);
	max[3][0] = i;
	if (max[1][0] < 1)
		max[1][0] = 1;
	max[2][0] = max[3][0] / max[1][0];
	if ((max[3][0] % max[1][0]) != 0)
		max[2][0]++;
	return (0);
}
