/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 22:36:38 by aanger            #+#    #+#             */
/*   Updated: 2018/04/07 02:54:17 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_print_numbers(void)
{
	int counter;

	counter = 47;
	while (counter++ < 57)
		ft_putchar(counter);
}
