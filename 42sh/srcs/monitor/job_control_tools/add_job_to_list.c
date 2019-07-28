/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_job_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:05:00 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:05:07 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include <stddef.h>

void			add_job_to_list(
				t_data *data)
{
	t_jobs		*job_case;

	if (data->job_control == NULL)
	{
		data->current_job->shell_job_number = 1;
		data->job_control = data->current_job;
		return ;
	}
	job_case = data->job_control;
	while (job_case->next != NULL)
		job_case = job_case->next;
	data->current_job->shell_job_number = job_case->shell_job_number + 1;
	job_case->next = data->current_job;
	data->current_job->previous = job_case;
}
