/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 22:47:23 by aanger            #+#    #+#             */
/*   Updated: 2018/04/28 18:04:14 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_draw_tetri(unsigned long long tab[5][27], char rslt[2][257],
			int i, int size)
{
	int					j[2];
	int					decal;
	int					count;
	unsigned long long	mask;

	j[0] = 0;
	decal = 0;
	count = 0;
	j[1] = 0;
	mask = 0x8000000000000000;
	while (count < 4)
	{
		while (tab[j[0]][i] == 0)
			j[0]++;
		if (j[0] != 0 && j[1] == 0)
			j[1] = 25 + 4 * (size - 5) - 1;
		if ((tab[j[0]][i] & mask) != 0 && count++ < 4)
			rslt[0][j[1]] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i];
		if (decal++ < size && j[1]++ < (size + 1) * (size + 1))
			mask >>= 1;
		if (decal == size && j[1]++ < 256 && !(decal = 0))
			mask >>= (16 - size);
		if (mask == 0 && j[0]++ < 4)
			mask = 0x8000000000000000;
	}
}

void	ft_fill_square(unsigned long long tab[5][27], char rslt[2][257],
			int size, int nbrtetri)
{
	int					i;
	int					j;

	j = 0;
	i = 0;
	while (i < nbrtetri)
	{
		ft_draw_tetri(tab, rslt, i, size);
		i++;
	}
	write(1, rslt[0], ft_strlen(rslt[0]));
}

void	ft_draw(unsigned long long tab[5][27], int size, int nbrtetri)
{
	char				rslt[2][257];
	int					i;
	int					j;

	i = 0;
	j = 0;
	rslt[1][0] = '\0';
	while (i < ((size + 1) * (size)))
	{
		if (j == size)
		{
			rslt[0][i] = '\n';
			j = -1;
		}
		else
			rslt[0][i] = '.';
		i++;
		j++;
	}
	rslt[0][i] = '\0';
	ft_fill_square(tab, rslt, size, nbrtetri);
}
