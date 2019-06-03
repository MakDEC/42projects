/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 20:51:39 by aanger            #+#    #+#             */
/*   Updated: 2018/04/29 02:32:44 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlens(int nb)
{
	int				rslt;
	unsigned int	cpynbr;

	rslt = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		rslt++;
		cpynbr = -nb;
	}
	else
		cpynbr = nb;
	while (cpynbr > 0)
	{
		rslt++;
		cpynbr /= 10;
	}
	return (rslt);
}
