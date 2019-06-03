/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 01:59:02 by aanger            #+#    #+#             */
/*   Updated: 2016/12/01 01:59:05 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	m;
	int		i;
	int		rslt[100];

	i = 0;
	m = n;
	if (m == 0)
		return (ft_putchar_fd('0', fd));
	if (m < 0)
	{
		ft_putchar_fd('-', fd);
		m *= -1;
	}
	rslt[i++] = m % 10 + 48;
	while (m /= 10)
		rslt[i++] = m % 10 + 48;
	i--;
	while (i >= 0)
		ft_putchar_fd(rslt[i--], fd);
}
