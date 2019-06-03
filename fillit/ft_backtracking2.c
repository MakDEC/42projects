/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 22:27:08 by aanger            #+#    #+#             */
/*   Updated: 2018/04/23 08:08:13 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_option3bis(unsigned long long tab[5][27],
		unsigned long long cpytab[5][27], int i, unsigned long long map[4])
{
	int	j;

	j = 0;
	while (tab[j][i] == 0)
		j++;
	if (i == 0)
		return (-1);
	tab[j][i] = 0;
	j = 0;
	tab[j][i] = cpytab[j][i];
	i--;
	while (tab[j][i] == 0 && j < 3)
		j++;
	map[j] -= tab[j][i];
	if (tab[j + 1][i] == 0)
		tab[j][i] >>= 1;
	else
	{
		map[j + 1] -= tab[j + 1][i];
		tab[j][i] >>= 1;
		tab[j + 1][i] >>= 1;
	}
	return (i);
}
