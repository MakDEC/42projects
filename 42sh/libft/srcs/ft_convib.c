/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 00:04:40 by aanger            #+#    #+#             */
/*   Updated: 2018/07/24 21:16:50 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*convert(char *rslt, int i, int j, long cpynbr)
{
	int	point;

	point = 1;
	while (i >= 0)
	{
		if (point == 8)
		{
			rslt[j] = '.';
			point = 0;
			j++;
		}
		if (ft_twopow(i) <= cpynbr)
		{
			rslt[j] = '1';
			cpynbr -= ft_twopow(i);
		}
		else
			rslt[j] = '0';
		j++;
		i--;
		point++;
	}
	return (rslt);
}

char			*ft_convib(int nb)
{
	char	*rslt;
	int		i;
	int		j;
	long	cpynbr;

	if (!(rslt = (char*)malloc(sizeof(char) * 36)))
		return (NULL);
	rslt[35] = '\0';
	i = 30;
	j = 0;
	rslt[0] = '0';
	cpynbr = nb;
	if (nb < 0)
	{
		rslt[0] = '1';
		cpynbr += 2147483648;
	}
	j++;
	convert(rslt, i, j, cpynbr);
	return (rslt);
}
