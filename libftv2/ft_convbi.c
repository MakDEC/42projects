/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convbi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 12:26:37 by aanger            #+#    #+#             */
/*   Updated: 2018/04/14 12:52:53 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convbi(char *bin)
{
	int	rslt;
	int	neg;
	int	i;
	int pow;

	rslt = 0;
	neg = 0;
	i = 0;
	pow = 30;
	if (bin[i] == '1')
		rslt -= 2147483648;
	i++;
	while (bin[i])
	{
		if (bin[i] == '1')
			rslt += ft_twopow(pow);
		i++;
		pow--;
	}
	return (rslt);
}
