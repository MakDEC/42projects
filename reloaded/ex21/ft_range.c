/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 03:37:38 by aanger            #+#    #+#             */
/*   Updated: 2018/04/07 04:51:49 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		count;
	int		*tab;

	if (min >= max)
	{
		tab = NULL;
		return (tab);
	}
	if (min < 0)
		count = max + -min;
	else
		count = max - min;
	if (!(tab = (int *)malloc(sizeof(int) * count + 1)))
		return (0);
	count = 0;
	min--;
	while (min++ < max - 1)
	{
		tab[count] = min;
		count++;
	}
	return (tab);
}
