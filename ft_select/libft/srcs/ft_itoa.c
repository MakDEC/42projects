/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 01:05:50 by aanger            #+#    #+#             */
/*   Updated: 2018/04/29 02:34:57 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	char	*rslt;
	long	cpynbr;
	int		i;

	i = ft_nbrlens(n);
	if (!(rslt = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	rslt[i] = '\0';
	if (n == 0)
	{
		rslt[0] = '0';
		return (rslt);
	}
	if (n < 0)
		rslt[0] = '-';
	cpynbr = n;
	if (cpynbr < 0)
		cpynbr = -cpynbr;
	i--;
	while (cpynbr > 0)
	{
		rslt[i--] = cpynbr % 10 + 48;
		cpynbr /= 10;
	}
	return (rslt);
}
