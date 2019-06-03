/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 04:58:13 by aanger            #+#    #+#             */
/*   Updated: 2018/10/15 16:07:51 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	finish(t_data *data)
{
	t_args_list	*temp;
	int			ever_sent;

	temp = data->args_list;
	ever_sent = 0;
	while (temp != NULL)
	{
		if (temp->select == 1)
		{
			if (ever_sent == 0)
				ever_sent = 1;
			else
				write(1, " ", 1);
			write(1, temp->arg, ft_strlen(temp->arg));
		}
		temp = temp->next;
	}
}
