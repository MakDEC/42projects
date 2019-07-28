/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 05:45:03 by aanger            #+#    #+#             */
/*   Updated: 2019/04/17 17:45:43 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "monitor.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int			pipeline_execution(
				t_data *data,
				t_pipe_line_data *pl_data)
{
	int		sync_pfd[2];

	pipe(sync_pfd);
	pl_data->pipe_line_current_case = pl_data->pipe_line_begin;
	if (data->current_job->background_job == 0)
		command_term_and_sig_configuration(data);
	first_command(data, pl_data->pipe_line_current_case, sync_pfd);
	pl_data->pipe_line_current_case = pl_data->pipe_line_current_case->next;
	while (pl_data->pipe_line_current_case->next != NULL)
	{
		intermediate_command(data, pl_data->pipe_line_current_case,
			sync_pfd);
		pl_data->pipe_line_current_case = pl_data->
			pipe_line_current_case->next;
	}
	last_command(data, pl_data->pipe_line_current_case, sync_pfd);
	return (0);
}
