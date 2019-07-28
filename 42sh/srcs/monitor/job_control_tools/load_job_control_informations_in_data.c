/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_job_control_informations_in_data.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:20:37 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:20:44 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"

void		load_job_control_informations_in_data(
			t_data *data,
			t_params_list *params_list)
{
	if (data->current_job->subshell_job == 0)
	{
		data->current_job->pid_to_check = params_list->pid;
		data->current_job->pgid_to_wait = params_list->pgid;
	}
	else
	{
		data->current_job->pid_to_check = data->
			current_job->subshell_pid;
		data->current_job->pgid_to_wait = data->
			current_job->subshell_pid;
	}
	new_background_current_job(data);
}
