/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:33:47 by aanger            #+#    #+#             */
/*   Updated: 2018/04/29 02:42:56 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	rslt[15];
	int		len;

	len = ft_nbrlen(n);
	rslt[len] = '\0';
	len--;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		while (len >= 0)
		{
			rslt[len--] = n % 10 + 48;
			n /= 10;
		}
		write(fd, rslt, ft_strlen(rslt));
	}
}
