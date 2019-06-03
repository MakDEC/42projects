/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:33:09 by aanger            #+#    #+#             */
/*   Updated: 2016/11/21 12:02:40 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	unsigned long long	i;
	unsigned long long	r;
	int					neg;

	r = 0;
	i = 0;
	neg = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
	|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		if (r >= 9223372036854775807)
			return (neg == 0 ? -1 : 0);
		i++;
	}
	return (neg == 0 ? r : -r);
}
