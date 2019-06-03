/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 22:18:08 by aanger            #+#    #+#             */
/*   Updated: 2018/04/07 02:53:47 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_print_alphabet(void)
{
	char counter;

	counter = 96;
	while (counter++ <= 121)
		ft_putchar(counter);
}
