/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:30:26 by aanger            #+#    #+#             */
/*   Updated: 2018/04/11 14:22:37 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long long	rslt;
	int					neg;

	rslt = 0;
	neg = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str ==
			'\r' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '+' || *str == '-')
		str++;
	if (*str < 48 && *str > 57)
		return (0);
	while (*str && *str >= 48 && *str <= 57)
	{
		rslt = rslt * 10 + *str - 48;
		if (rslt > 9223372036854775807)
			return (neg == 1 ? 0 : -1);
		str++;
	}
	return (neg == 1 ? -rslt : rslt);
}
