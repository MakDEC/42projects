/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:40:48 by aanger            #+#    #+#             */
/*   Updated: 2018/06/07 17:31:37 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cathex(unsigned long long hex, char *rslt, int prefix, int capitalize)
{
	int					i;
	unsigned long long	cpyhex;

	i = 0;
	i = ft_strlen(rslt);
	cpyhex = hex;
	if (hex == 0)
		return (rslt[i] = '0');
	if (prefix == 1)
	{
		rslt[i] = '0';
		rslt[i + 1] = 'x';
		i += 2;
	}
	while ((cpyhex /= 16) > 0)
		i++;
	while (hex > 0)
	{
		rslt[i--] = "0123456789abcdef"[hex % 16];
		if (capitalize == 1)
			rslt[i + 1] = "0123456789ABCDEF"[hex % 16];
		hex /= 16;
	}
	return (0);
}
