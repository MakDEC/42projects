/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_stopped_child_management.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:50:19 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:24:07 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "libft.h"
#include <sys/wait.h>

/*
**	As notified in the waitpid man 2 section, WCOREDUMP
**	macro isn't specified in POSIX.1-2001, we then have to check
**	if it is defined to use it.
*/

#ifdef WCOREDUMP

int		signal_stopped_child_management(
			t_data *data,
			t_params_list *params_list)
{
	if (WIFSIGNALED(data->current_job->job_return_value) != 0)
	{
		if (WCOREDUMP(data->current_job->job_return_value) != 0)
			ft_putstr("Quit (core dumped)\n");
		else
			ft_putchar('\n');
	}
	else if (WIFSTOPPED(data->current_job->job_return_value) != 0)
	{
		load_job_control_informations_in_data(data, params_list);
		add_job_to_list(data);
		new_background_current_job(data);
		ft_putchar('\n');
		display_job_status(data, data->current_job);
		data->current_job = NULL;
		return (data->last_cmd_status);
	}
	return (data->last_cmd_status);
}

#else

int		signal_stopped_child_management(
			t_data *data,
			t_params_list *params_list)
{
	if (WIFSIGNALED(data->current_job->job_return_value) != 0)
		ft_putchar('\n');
	else if (WIFSTOPPED(data->current_job->job_return_value) != 0)
	{
		load_job_control_informations_in_data(data, params_list);
		add_job_to_list(data);
		new_background_current_job(data);
		ft_putchar('\n');
		display_job_status(data, data->current_job);
		data->current_job = NULL;
		return (data->last_cmd_status);
	}
	return (data->last_cmd_status);
}

#endif
