/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_job_and_free_memory.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:05:33 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:06:02 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stddef.h>

t_jobs			*finish_job_and_free_memory(
				t_data *data,
				t_jobs *job_case)
{
	display_job_status(data, job_case);
	if (job_case->previous != NULL)
		job_case->previous->next = job_case->next;
	else
		data->job_control = job_case->next;
	if (job_case->next != NULL)
		job_case->next->previous = job_case->previous;
	if (job_case == data->back_current_job)
	{
		data->back_current_job = data->back_previous_job;
		data->back_previous_job = NULL;
	}
	else if (job_case == data->back_previous_job)
		data->back_previous_job = NULL;
	data->current_job = job_case;
	job_case = job_case->next;
	clear_current_case(data);
	data->current_job = NULL;
	return (job_case);
}
