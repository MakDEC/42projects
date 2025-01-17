/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 02:05:42 by aanger            #+#    #+#             */
/*   Updated: 2018/04/14 21:51:03 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	rslt[ft_nbrlen(n) + 1];
	int		len;

	len = ft_nbrlen(n);
	rslt[len] = '\0';
	len--;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		while (len >= 0)
		{
			rslt[len--] = n % 10 + 48;
			n /= 10;
		}
		ft_putstr(rslt);
	}
}
