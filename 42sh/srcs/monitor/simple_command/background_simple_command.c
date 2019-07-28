/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_simple_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:32:10 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:32:12 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <sys/wait.h>
#include <unistd.h>

int			background_simple_command(
				t_data *data,
				t_params_list *params_list,
				int sync_pfd[2])
{
	char	buf;

	read(sync_pfd[0], &buf, 1);
	close(sync_pfd[1]);
	read(sync_pfd[0], &buf, 1);
	close(sync_pfd[0]);
	if (data->current_job->subshell_job == 1)
		waitpid(params_list->pid, &data->current_job->job_return_value,
				WUNTRACED);
	else
		load_job_control_informations_in_data(
			data, params_list);
	return (0);
}
