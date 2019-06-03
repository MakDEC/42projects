/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_null_or_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 01:00:56 by aanger            #+#    #+#             */
/*   Updated: 2018/07/23 21:55:57 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

int			max_width(char order[BUFF_SIZE1][BUFF_SIZE2], char options[255])
{
	size_t			max;
	int				i;

	max = 0;
	i = -1;
	while (order[++i][0] != '\0')
		if ((order[i][0] != '.' || options['a'] == 1)
					&& ft_strlen(order[i]) > max)
			max = ft_strlen(order[i]);
	return (max);
}

int			lines(char order[BUFF_SIZE1][BUFF_SIZE2], char options[255],
					int max[4][1])
{
	int				i;

	i = 0;
	if ((max[0][0] = max_width(order, options)) == 0)
		return (-1);
	while ((max[0][0] % 8) != 0)
		max[0][0]++;
	if (max[0][0] == 8)
		max[0][0] += 8;
	while (order[i][0] != '\0')
		i++;
	max[1][0] = (screenwidth() / max[0][0]);
	max[2][0] = i / max[1][0];
	if ((i % max[1][0]) != 0)
		max[2][0]++;
	i = 0;
	return (0);
}

int			args_1(char order[BUFF_SIZE1][BUFF_SIZE2], char options[255],
					char rslt[10000])
{
	int				i;

	i = 0;
	while (i < BUFF_SIZE1 && order[i][0])
	{
		if (order[i][0] != '.' || options['a'] == 1)
		{
			if (ft_strlen(rslt) + ft_strlen(order[i]) > 10000)
			{
				write(1, rslt, ft_strlen(rslt));
				ft_bzero(rslt, 10000);
			}
			ft_strcat(rslt, order[i]);
			ft_strcat(rslt, "\n");
		}
		i++;
	}
	return (write(1, rslt, ft_strlen(rslt)));
	return (1);
}

int			fill_buff(char order[BUFF_SIZE1][BUFF_SIZE2], char rslt[10000],
						char options[255], int max[4][1])
{
	int				i[3];
	int				len;

	if ((i[0] = lines(order, options, max) - 1) <= -2)
		return (0);
	i[1] = -1;
	i[2] = -1;
	while (++i[2] < max[2][0] && (i[0]++ > -10))
	{
		while (++i[1] < max[1][0] && (len = 0) != -1)
		{
			ft_strcat(rslt, order[i[0] + (max[2][0] * i[1])]);
			len = ft_strlen(order[i[0] + (max[2][0] * i[1])]);
			if (len % 8 != 0 && (i[1] + 1) < max[1][0]
					&& ft_strcat(rslt, "\t") > 0)
				while (len % 8 != 0)
					len++;
			while (len < max[0][0] && (len += 8) != 0 && (i[1] + 1) < max[1][0])
				ft_strcat(rslt, "\t");
		}
		ft_strcat(rslt, "\n");
		i[1] = -1;
	}
	return (write(1, rslt, ft_strlen(rslt)));
}

int			args_null_or_a(char options[255],
				char order[BUFF_SIZE1][BUFF_SIZE2])
{
	char			rslt[10000];
	int				max[4][1];

	ft_bzero(rslt, 10000);
	if (options['1'] == 1)
		return (args_1(order, options, rslt));
	return (fill_buff(order, rslt, options, max));
}
