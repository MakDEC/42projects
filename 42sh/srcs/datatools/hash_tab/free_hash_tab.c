/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hash_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:26:50 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 00:52:56 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stdlib.h>

static void	hash_tab_recursive_free(
				t_hash_tab *temp)
{
	int			i;

	i = -1;
	if (temp == NULL)
		return ;
	while (++i < 95)
	{
		if (temp->hash_tab[i] != NULL)
			free_hash_tab(temp->hash_tab[i]);
	}
	if (temp->name != NULL)
		free(temp->name);
	if (temp->path != NULL)
		free(temp->path);
	free(temp);
}

void		free_hash_tab(
					t_hash_tab *temp)
{
	hash_tab_recursive_free(temp);
}
