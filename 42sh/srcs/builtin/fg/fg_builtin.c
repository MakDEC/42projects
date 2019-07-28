/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 05:24:16 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 05:25:10 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "libft.h"
#include <sys/wait.h>

#define MISUSE_OF_SHELL_BUILTIN 2

static t_jobs	*fg_print_usage(
						t_data *data,
						t_params_list *params_list)
{
	data->last_cmd_status = MISUSE_OF_SHELL_BUILTIN;
	ft_putstr_fd("42sh: fg: Bad number of arguments\n", params_list->fd[2]);
	ft_putstr_fd("usage: fg [job_id]\n", params_list->fd[2]);
	return (NULL);
}

static t_jobs	*set_job_to_resume(
						t_data *data,
						t_params_list *params_list)
{
	if (params_list->argc >= 2)
		return (fg_print_usage(data, params_list));
	if (params_list->argc == 1)
		return (data->back_current_job);
	return (NULL);
}

int				fg_builtin(
						t_data *data,
						t_params_list *params_list)
{
	t_jobs	*job_to_resume;
	t_jobs	*back;

	job_to_resume = set_job_to_resume(data, params_list);
	if (job_to_resume == NULL)
		return (1);
	ft_putendl(job_to_resume->full_buf);
	if (tcsetpgrp(0, job_to_resume->pgid_to_wait) != 0)
	{
		ft_putstr_fd("42sh: Fatal Error, tcsetgprp failed\n", 2);
		exit (-1);
	}
	command_term_and_sig_configuration(data);
	kill(-job_to_resume->pgid_to_wait, SIGCONT);
	waitpid(job_to_resume->pid_to_check,
		&job_to_resume->job_return_value, WUNTRACED);
	shell_term_and_sig_configuration(data);
	if (tcsetpgrp(0, getpid()) != 0)
	{
		ft_putstr_fd("42sh: Fatal Error: tcsetpgrp failed\n", 2);
		exit(-1);
	}
	back = data->current_job;
	data->current_job = job_to_resume;
	signal_stopped_child_management(data, params_list);
	data->current_job = back;
	return (0);
}
