/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:15:09 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:27:09 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stddef.h>

int			job_loader(
				t_data *data)
{
	export_command_buf(data);
	if (data->current_job->background_job == 1)
	{
		if (data->current_job->logical_job == 1)
			data->current_job->subshell_job = 1;
		add_job_to_list(data);
	}
	if (data->current_job->subshell_job == 0)
		and_logical_monitor(data, data->current_job->and_list_begin);
	else
		subshell_execution(data);
	if (data->current_job != NULL && data->current_job->background_job == 1)
		data->current_job = NULL;
	else
		clear_current_case(data);
	return (0);
}
