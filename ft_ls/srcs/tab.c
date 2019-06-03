/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:58:16 by aanger            #+#    #+#             */
/*   Updated: 2018/08/11 17:16:04 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		rev_tab(t_infos **tab)
{
	t_infos		*swap;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (tab[i + 1] != NULL)
		i++;
	while (j < i)
	{
		swap = tab[i];
		tab[i] = tab[j];
		tab[j] = swap;
		i--;
		j++;
	}
}

t_infos		**tab_t_infos(t_infos *debut)
{
	t_infos		**tab;
	t_infos		*liste;
	int			i;
	int			j;

	liste = debut;
	i = 0;
	while (liste != NULL)
	{
		liste = liste->next;
		i++;
	}
	if (!(tab = (t_infos**)malloc(sizeof(t_infos*) * (i + 1))))
		exit(1);
	j = -1;
	liste = debut;
	while (++j < i)
	{
		tab[j] = liste;
		liste = liste->next;
	}
	tab[j] = NULL;
	return (tab);
}
