/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completed_jobs_verification.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:06:39 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:13:48 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>

static t_jobs		*pid_to_check_completed(
						t_data *data,
						t_jobs *job_case)
{
	kill_zombies_process(job_case->pgid_to_wait);
	if (waitpid(-(job_case->pgid_to_wait), NULL, WNOHANG | WUNTRACED) == -1)
		job_case = finish_job_and_free_memory(data, job_case);
	else
		job_case = job_case->next;
	return (job_case);
}

/*
**		This function checks if some child has completed.
**	We dont handle them with sigchld to display informations at the end of
**	the monitor loop.
**	Moreover, we dont need a global with this implementation.
**	The conditions in the loop are :
**		-> We check if the principal command has finished (last command
**	of a pipe, subshell or just a simple command
**		-> To be sure to don't let zombies alive, we wait for all
**	the process with the same pgid and set the job as completed only if
**	they have all returned.
**		-> We change case
*/

static t_jobs		*check_if_all_proccess_have_completed(
						t_data *data,
						t_jobs *job_case)
{
	kill_zombies_process(job_case->pgid_to_wait);
	if (waitpid(-(job_case->pgid_to_wait), NULL, WNOHANG) == -1)
		job_case = finish_job_and_free_memory(data, job_case);
	else
		job_case = job_case->next;
	return (job_case);
}

void				completed_jobs_verification(
						t_data *data)
{
	t_jobs			*job_case;

	job_case = data->job_control;
	while (job_case != NULL)
	{
		if (job_case->pid_to_check == -1)
		{
			job_case = job_case->next;
			continue ;
		}
		if (waitpid(job_case->pid_to_check, &job_case->job_return_value,
						WNOHANG | WUNTRACED) > 0)
			job_case = pid_to_check_completed(data, job_case);
		else if (waitpid(-(job_case->pgid_to_wait), NULL, WNOHANG) > 0)
			job_case = check_if_all_proccess_have_completed(data, job_case);
		else
			job_case = job_case->next;
	}
}
