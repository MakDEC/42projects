/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mall_args_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:44:58 by aanger            #+#    #+#             */
/*   Updated: 2018/07/24 21:50:31 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		malloc_args_1(t_infos **tab, char *rslt)
{
	int				i;
	t_infos			*tmp;

	i = -1;
	while (tab[++i] != NULL)
	{
		tmp = tab[i];
		if (ft_strlen(rslt) + tmp->size > 1000000)
		{
			write(1, rslt, ft_strlen(rslt));
			ft_bzero(rslt, 1000000);
		}
		ft_strcat(rslt, tmp->buf);
		ft_strcat(rslt, "\n");
	}
	return (write(1, rslt, ft_strlen(rslt)));
}

static void		deuxieme_boucle(size_t i[3], size_t max[4][1], t_infos **tab,
					char *rslt)
{
	size_t	len;
	t_infos	*tmp;

	if (i[0] + (max[2][0] * i[1]) >= max[3][0])
		return ;
	tmp = tab[i[0] + (max[2][0] * i[1])];
	len = tmp->size;
	if (tmp->buf != NULL)
		ft_strcat(rslt, tmp->buf);
	len = tmp->size;
	if (len % 8 != 0 && (i[1]) < max[1][0])
	{
		ft_strcat(rslt, "\t");
		while (len % 8 != 0)
			len++;
	}
	while (len < max[0][0] && (len += 8) != 0 &&
				(i[1] + 1) <= max[1][0])
		ft_strcat(rslt, "\t");
}

static int		malloc_fill_buff(t_infos **tab, char *rslt,
						size_t max[4][1])
{
	size_t			i[3];
	size_t			len;

	i[0] = malloc_lines(tab, max);
	i[1] = -1;
	i[2] = -1;
	while (++i[2] < max[2][0])
	{
		while (++i[1] < max[1][0] && (len = 0) != -1)
			deuxieme_boucle(i, max, tab, rslt);
		i[0]++;
		ft_strcat(rslt, "\n");
		i[1] = -1;
	}
	return (write(1, rslt, ft_strlen(rslt)));
}

int				malloc_args_null(char options[255], t_infos **tab)
{
	char			*rslt;
	size_t			max[4][1];
	int				i;

	i = 0;
	if (options['r'] == 1)
		rev_tab(tab);
	if (!(rslt = (char*)malloc(sizeof(char) * 1000000)))
		return (-1);
	ft_bzero(rslt, 1000000);
	if (options['1'] == 1)
		malloc_args_1(tab, rslt);
	else
		malloc_fill_buff(tab, rslt, max);
	free(rslt);
	rslt = NULL;
	return (0);
}
