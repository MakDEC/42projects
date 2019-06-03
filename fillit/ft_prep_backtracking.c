/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:03:49 by aanger            #+#    #+#             */
/*   Updated: 2018/04/23 07:55:35 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_prep_backtracking(unsigned long long tab[5][27],
			unsigned long long map[4], int size)
{
	unsigned long long	cpytab[5][27];
	int					i;
	int					j;

	i = 0;
	j = 0;
	while (tab[0][i])
	{
		cpytab[j][i] = tab[0][i];
		while (++j < 3)
		{
			tab[j][i] = 0;
			cpytab[j][i] = 0;
		}
		j = 0;
		i++;
	}
	cpytab[0][i] = '\0';
	if ((ft_backtracking(tab, map, cpytab, size) == 1))
		return (1);
	return (0);
}

int		ft_prep_map(int size, unsigned long long tab[5][27],
			unsigned long long map[4], unsigned long long mask)
{
	int					i;
	int					height;
	int					sizeb;

	sizeb = -1;
	height = 0;
	i = 0;
	while (height < size)
	{
		while (++sizeb < size)
		{
			map[i] = map[i] ^ mask;
			mask >>= 1;
		}
		sizeb = -1;
		mask >>= (16 - size);
		if (++height % 4 == 0)
		{
			mask = 0x8000000000000000;
			i++;
		}
	}
	if (ft_prep_backtracking(tab, map, size) == 1)
		return (1);
	return (0);
}

int		ft_initialize_map(unsigned long long tab[5][27])
{
	int					size;
	unsigned long long	map[4];
	int					i;
	unsigned long long	mask;

	mask = 0x8000000000000000;
	i = -1;
	while (++i < 4)
		map[i] = ~0;
	i = 0;
	size = 2;
	while (ft_prep_map(size, tab, map, mask) == 0)
	{
		i = -1;
		while (++i < 4)
			map[i] = ~0;
		size++;
	}
	return (1);
}
