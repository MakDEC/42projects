/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 05:02:40 by aanger            #+#    #+#             */
/*   Updated: 2016/11/17 05:02:42 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	size;
	int		neg;
	char	*rslt;
	long	f;

	f = n;
	neg = 0;
	size = ft_nbdigits((int)f);
	if (f < 0 && size++)
	{
		neg = 1;
		f *= -1;
	}
	if (!(rslt = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	rslt[size] = '\0';
	while (size > 0)
	{
		rslt[size-- - 1] = f % 10 + 48;
		f /= 10;
	}
	size--;
	if (neg == 1)
		rslt[0] = '-';
	return (rslt);
}
