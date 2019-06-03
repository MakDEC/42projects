/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lire_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 20:35:36 by aanger            #+#    #+#             */
/*   Updated: 2018/08/11 18:05:33 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			analyse_args(char *dir, char options[255])
{
	char	order[BUFF_SIZE1][BUFF_SIZE2];
	int		i;
	char	buffer[BUFF_SIZE2];

	i = 0;
	while (dir[i])
		i++;
	if (options['R'] == 1)
		return (args_r(dir, options));
	if (orderer(dir, order, options) != 1)
		return (0);
	if (options['l'] == 1 || options['o'] == 1)
	{
		if (readlink(dir, buffer, BUFF_SIZE2) != -1 && dir[i - 1] != '/')
			return (slink(dir, options[10]));
		options[10] = write_total(dir, options);
		if (options['o'] == 1)
			return (args_o(dir, options, order));
		return (args_la(dir, options, order));
	}
	args_null_or_a(options, order);
	return (0);
}
