/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 01:55:59 by aanger            #+#    #+#             */
/*   Updated: 2018/04/07 06:19:28 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int rslt;

	rslt = nb;
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (1);
	if (nb >= 13)
		return (0);
	while (nb-- > 2)
		rslt = rslt * nb;
	return (nb >= 1 ? rslt : 0);
}
