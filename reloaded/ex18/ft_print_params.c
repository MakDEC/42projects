/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 05:22:28 by aanger            #+#    #+#             */
/*   Updated: 2018/04/07 05:24:00 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

int		main(int argc, char **argv)
{
	int counter;
	int i;

	counter = 1;
	if (argc == 1)
		return (0);
	while (counter < argc)
	{
		i = -1;
		while (argv[counter][++i] != 0)
			ft_putchar(argv[counter][i]);
		ft_putchar('\n');
		counter++;
	}
	return (0);
}
