/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:30:52 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 18:30:55 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stddef.h>

void			display_all_jobs(
				t_data *data)
{
	t_jobs		*job_case;

	job_case = data->job_control;
	while (job_case != NULL)
	{
		display_job_status(data, job_case);
		job_case = job_case->next;
	}
}

int			jobs(
				t_data *data)
{
	display_all_jobs(data);
	return (0);
}
