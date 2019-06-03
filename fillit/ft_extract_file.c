/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exctract_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:12:41 by aanger            #+#    #+#             */
/*   Updated: 2018/04/28 18:04:34 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_decal(char *buf)
{
	int					i;
	int					j;
	int					k;
	int					l;

	i = 0;
	j = 5;
	k = 10;
	l = 15;
	if (buf[0] == '#' || buf[5] == '#' || buf[10] == '#' || buf[15] == '#')
		return (0);
	while ((buf[i] != '#' && buf[j] != '#' && buf[k] != '#' && buf[l] != '#')
			&& buf[i])
	{
		i++;
		j++;
		k++;
		l++;
	}
	return (i);
}

unsigned long long	ft_conv_to_bin(char *buf)
{
	unsigned long long	rslt;
	int					i;
	int					j;
	unsigned int		temp_rslt;

	j = 0;
	rslt = 0;
	i = 0;
	temp_rslt = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' && i <= 19)
		{
			rslt <<= 16;
			temp_rslt <<= ft_decal(&buf[0]);
			rslt += temp_rslt;
			temp_rslt = 0;
			j = -1;
		}
		if (buf[i++] == '#')
			temp_rslt += (1 << (15 - j));
		j++;
	}
	return (rslt);
}

int					ft_count(char *buf, int ft, int i)
{
	int					count;

	count = 0;
	if (ft == 1)
	{
		if (i > 0 && buf[i - 1] == '#')
			count++;
		if (i < 19 && buf[i + 1] == '#')
			count++;
		if (i > 4 && buf[i - 5] == '#')
			count++;
		if (i < 16 && buf[i + 5] == '#')
			count++;
	}
	i = 0;
	if (ft == 2)
		while (buf[i])
		{
			if (buf[i] == '#')
				count++;
			i++;
		}
	return (count);
}

unsigned long long	ft_check_extract(char *buf)
{
	int					count;
	unsigned long long	rslt;
	int					i;

	count = 0;
	rslt = 0;
	i = 0;
	while (buf[i])
	{
		if ((buf[i] != '.' && buf[i] != '#' && buf[i] != '\n') || ((i + 1)
					% 5 == 0 && buf[i] != '\n'))
			return (0);
		if (buf[i] == '#')
			count += ft_count(&buf[0], 1, i);
		i++;
	}
	rslt = ft_conv_to_bin(&buf[0]);
	if (rslt != 0)
		while (rslt < 281474976710656)
			rslt <<= 16;
	if ((count == 6 || count == 8) && (ft_count(&buf[0], 2, i) == 4) &&
			buf[i - 1] == '\n')
		return (rslt);
	return (0);
}

int					ft_read_file(int fd)
{
	unsigned long long	tab[5][27];
	char				buf[21];
	int					i;
	int					temp;
	int					nbr_read;

	i = 0;
	while ((nbr_read = read(fd, buf, 21)) != 0)
	{
		if (nbr_read < 20)
			return (0);
		tab[0][i] = 0;
		tab[0][i] = ft_check_extract(buf);
		if (tab[0][i] == 0)
			return (0);
		tab[4][i] = '\0';
		i++;
		temp = nbr_read;
	}
	tab[0][i] = '\0';
	if (temp != 20)
		return (0);
	if (i != 0)
		ft_initialize_map(tab);
	return (1);
}
