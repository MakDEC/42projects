/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 03:35:10 by aanger            #+#    #+#             */
/*   Updated: 2016/11/17 03:37:00 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	m;
	int		i;
	char	rslt[10];

	i = 0;
	m = n;
	if (m == 0)
		ft_putchar('0');
	if (m < 0)
	{
		ft_putchar('-');
		m *= -1;
	}
	rslt[i++] = m % 10 + '0';
	if (m == 0)
		i--;
	while (m /= 10)
		rslt[i++] = m % 10 + '0';
	i--;
	while (i >= 0)
		ft_putchar(rslt[i--]);
}
