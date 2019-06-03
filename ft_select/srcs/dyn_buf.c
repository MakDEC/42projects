/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_buf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 22:39:20 by aanger            #+#    #+#             */
/*   Updated: 2018/10/16 23:28:54 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

#include <stdio.h>

void		dyn_buf(t_data *data, char character)
{
	int			i;
	t_args_list	*temp;

	i = 0;
	while (data->dyn_sr[i] != 0)
		i++;
	if (i == 98)
		return ;
	data->dyn_sr[i] = character;
	temp = data->args_list;
	i = 0;
	while (temp != NULL && ft_strncmp(temp->arg,
	data->dyn_sr, ft_strlen(data->dyn_sr)) != 0)
	{
		temp = temp->next;
		i++;
	}
	if (temp != NULL)
	{
		data->curs_po = i;
		set_decal(data);
	}
}
