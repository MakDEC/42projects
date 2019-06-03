/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int_bin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 06:00:17 by aanger            #+#    #+#             */
/*   Updated: 2016/12/13 06:00:22 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*binrslt(char *rslt, int nb, int count, int power)
{
	int		i;

	i = 0;
	while (nb > 0)
	{
		rslt[i] = 48;
		if (nb >= ft_twopow(power))
		{
			rslt[i] = 49;
			nb -= ft_twopow(power);
		}
		i++;
		power--;
		count++;
	}
	while (count++ <= 31)
		rslt[i++] = 48;
	rslt[i] = '\0';
	return (rslt);
}

char			*ft_conv_int_bin(int nb)
{
	int		count;
	int		power;
	char	*rslt;

	power = 32;
	count = 1;
	while (nb < ft_twopow(--power))
		count++;
	if (!(rslt = (char*)malloc(sizeof(char) * power)))
		return (0);
	rslt = binrslt(rslt, nb, count, power);
	return (rslt);
}
