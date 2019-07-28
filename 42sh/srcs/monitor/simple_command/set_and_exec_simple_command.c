/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_exec_simple_command.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:32:47 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:33:07 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <unistd.h>

int		set_and_exec_simple_command(
			t_data *data,
			t_params_list *params_list,
			int sync_pfd[2])
{
	if (data->current_job->subshell_job == 0)
		setpgid(params_list->pid, params_list->pid);
	else
		setpgid(params_list->pid, data->current_job->subshell_pid);
	if (data->current_job->background_job == 0)
	{
		tcsetpgrp(0, getpid());
		command_term_and_sig_configuration(data);
	}
	apply_redirections(params_list);
	load_children_shell_level(data);
	write(sync_pfd[1], "0", 1);
	close(sync_pfd[0]);
	close(sync_pfd[1]);
	execve(params_list->cmd_path, params_list->params, data->env);
	return (-1);
}
