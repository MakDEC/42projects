/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_hash_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:45:06 by aanger            #+#    #+#             */
/*   Updated: 2019/07/12 23:59:51 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include <stdlib.h>

t_hash_tab		*search_in_hash_tab(
					t_hash_tab *temp,
					char *name)
{
	int		i;

	i = 0;
	if (!name)
		return (NULL);
	if (temp == NULL)
		return (NULL);
	while (name[i] != 0 && name[i] > 32)
	{
		if (temp->hash_tab[(int)(name[i] - 33)] == NULL)
			return (NULL);
		temp = temp->hash_tab[(int)(name[i] - 33)];
		i++;
	}
	if (temp->name != NULL && ft_strcmp(temp->name, name) == 0)
		return (temp);
	return (NULL);
}
