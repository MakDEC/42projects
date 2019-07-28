/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_logical_monitor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:51:20 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 18:54:10 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stddef.h>

int		and_logical_monitor(
			t_data *data,
			t_and_list *and_list)
{
	int					ret_value;

	ret_value = 1;
	while (and_list != NULL)
	{
		if ((ret_value = or_logical_monitor(data,
							and_list->or_list_begin)) == 0)
			and_list = and_list->and_list_next;
		else
			break ;
	}
	return (ret_value);
}
