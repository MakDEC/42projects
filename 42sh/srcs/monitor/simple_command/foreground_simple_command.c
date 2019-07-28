/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreground_simple_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:32:20 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:32:23 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <unistd.h>
#include <sys/wait.h>

int		foreground_simple_command(
			t_data *data,
			t_params_list *params_list,
			int sync_pfd[2])
{
	close(sync_pfd[1]);
	close(sync_pfd[0]);
	waitpid(params_list->pid, &data->current_job->job_return_value,
			WUNTRACED);
	tcsetpgrp(1, getpid());
	shell_term_and_sig_configuration(data);
	data->last_cmd_status = data->current_job->job_return_value;
	return (signal_stopped_child_management(data, params_list));
}
