/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bin_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 06:01:04 by aanger            #+#    #+#             */
/*   Updated: 2016/12/13 06:01:06 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conv_bin_int(char *s)
{
	int	rslt;
	int	count;
	int	size;

	count = 0;
	rslt = 0;
	size = ft_strlen(s);
	while (count < size)
	{
		if (s[count] == 49)
			rslt += (ft_twopow(size - count));
		if (s[count] > 49)
			return (-1);
		count++;
	}
	return (rslt);
}
