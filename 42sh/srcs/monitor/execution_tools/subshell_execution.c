/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:54:55 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 18:59:29 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static int		subshell_process(
					t_data *data,
					int sync_pfd[2])
{
	setpgid(0, 0);
	close(sync_pfd[0]);
	close(sync_pfd[1]);
	and_logical_monitor(data, data->current_job->and_list_begin);
	exit(data->last_cmd_status);
}

static void		background_subshell(
					t_data *data,
					int sync_pfd[2])
{
	char		buf;

	close(sync_pfd[1]);
	read(sync_pfd[0], &buf, 1);
	close(sync_pfd[0]);
	data->current_job->pid_to_check = data->current_job->
		subshell_pid;
	data->current_job->pgid_to_wait = data->current_job->
		subshell_pid;
	display_job_number_and_pid(data);
}

void			subshell_execution(
					t_data *data)
{
	int			sync_pfd[2];

	pipe(sync_pfd);
	data->current_job->subshell_pid = fork();
	if (data->current_job->subshell_pid == 0)
		subshell_process(data, sync_pfd);
	else
	{
		if (data->current_job->background_job == 0)
		{
			waitpid(data->current_job->subshell_pid,
					&data->last_cmd_status, 0);
			tcsetpgrp(0, getpid());
		}
		else
			background_subshell(data, sync_pfd);
	}
}
