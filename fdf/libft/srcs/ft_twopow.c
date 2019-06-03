/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twopow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 00:10:25 by aanger            #+#    #+#             */
/*   Updated: 2018/04/29 02:32:54 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_twopow(int nb)
{
	int	i;

	i = 1;
	while (nb > 0)
	{
		i *= 2;
		nb--;
	}
	return (i);
}
