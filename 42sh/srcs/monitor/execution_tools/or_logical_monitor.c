/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_logical_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:53:59 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 18:54:29 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stddef.h>

int						or_logical_monitor(
							t_data *data,
							t_pipe_line_data *or_list)
{
	while (or_list != NULL)
	{
		if (prepare_verify_and_exec_pipeline(data, or_list) == 0)
			return (0);
		or_list = or_list->next;
	}
	return (1);
}
