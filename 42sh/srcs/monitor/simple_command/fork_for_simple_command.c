/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_for_simple_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:32:31 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 02:54:43 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <unistd.h>

int		fork_for_simple_command(
			t_data *data,
			t_params_list *params_list)
{
	int	sync_pfd[2];

	pipe(sync_pfd);
	data->last_cmd_status = 0;
	params_list->pid = fork();
	if (params_list->pid == 0)
		set_and_exec_simple_command(data, params_list, sync_pfd);
	else
	{
		params_list->pgid = params_list->pid;
		if (data->current_job->background_job == 0)
			return (foreground_simple_command(
					data, params_list, sync_pfd));
		else
			return (background_simple_command(
					data, params_list, sync_pfd));
	}
	return (-1);
}
