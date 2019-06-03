/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:30:20 by aanger            #+#    #+#             */
/*   Updated: 2018/04/23 07:52:26 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_option3(unsigned long long tab[5][27],
			unsigned long long cpytab[5][27], int i, unsigned long long map[4])
{
	int					j;

	j = 0;
	while (tab[j][i] == 0)
		j++;
	if ((tab[j][i] & 1) == 0)
		tab[j][i] >>= 1;
	else
	{
		if (j == 3)
			i = ft_option3bis(tab, cpytab, i, map);
		else
		{
			tab[j + 1][i] >>= 1;
			tab[j + 1][i] += 0x8000000000000000;
			tab[j][i] >>= 1;
		}
	}
	return (i);
}

int		ft_option4(unsigned long long tab[5][27], int i, int j)
{
	if ((tab[j][i] & 1) == 0)
	{
		tab[j][i] >>= 1;
		tab[j + 1][i] >>= 1;
	}
	else
	{
		tab[j][i] >>= 1;
		tab[j + 1][i] >>= 1;
		tab[j + 1][i] += 0x8000000000000000;
	}
	return (i);
}

int		ft_option(unsigned long long tab[5][27], unsigned long long map[4],
			int i, int option)
{
	int					j;

	j = 0;
	while (tab[j][i] == 0 && j < 3)
		j++;
	if (option == 1)
		map[j] += tab[j][i];
	if (option == 2)
	{
		map[j] += tab[j][i];
		map[j + 1] += tab[j + 1][i];
	}
	i++;
	return (i);
}

int		ft_binary_comparison(unsigned long long tab[5][27],
		unsigned long long cpytab[5][27], int i, unsigned long long map[4])
{
	int					option;
	int					j;

	j = 0;
	while (tab[j][i] == 0 && j < 3)
		j++;
	if (((tab[j][i] & map[j]) == 0) && (tab[j + 1][i] == 0))
		option = 1;
	if ((tab[j + 1][i] != 0) && ((tab[j][i] & map[j]) == 0) &&
			((tab[j + 1][i] & map[j + 1]) == 0))
		option = 2;
	if ((tab[j + 1][i] == 0) && ((tab[j][i] & map[j]) != 0))
		option = 3;
	if ((tab[j + 1][i] != 0) && (((tab[j][i] & map[j]) != 0) ||
				((tab[j + 1][i] & map[j + 1]) != 0)))
		option = 4;
	if (option == 1 || option == 2)
		i = ft_option(tab, map, i, option);
	if (option == 3)
		i = ft_option3(tab, cpytab, i, map);
	if (option == 4)
		i = ft_option4(tab, i, j);
	return (i);
}

int		ft_backtracking(unsigned long long tab[5][27],
		unsigned long long map[4], unsigned long long cpytab[5][27], int size)
{
	int					i;
	int					j;

	i = 0;
	j = 0;
	while (1)
	{
		while (cpytab[j][i] == 0 && j < 3)
			j++;
		i = ft_binary_comparison(cpytab, tab, i, map);
		if (i == -1)
			return (0);
		if (!(tab[0][i]))
		{
			ft_draw(cpytab, size, i);
			return (1);
		}
		j = 0;
	}
	return (0);
}
