/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 03:25:47 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 00:11:44 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

static void		set_and_exec_last_command(
					t_data *data,
					t_params_list *params_list,
					int sync_pfd[2])
{
	char		buf;

	if (data->current_job->subshell_job == 0)
		setpgid(params_list->pid, params_list->previous->pgid);
	else
		setpgid(params_list->pid, data->current_job->subshell_pid);
	write(sync_pfd[1], "0", 1);
	close(sync_pfd[1]);
	read(sync_pfd[0], &buf, 1);
	close(sync_pfd[0]);
	if (check_builtin(data, params_list) != -1)
		exit(0);
	dup2(params_list->previous->pfd[0], 0);
	close(params_list->previous->pfd[0]);
	apply_redirections(params_list);
	execve(params_list->cmd_path, params_list->params, data->env);
}

/*
**	POSIX.1, section 2.9.2 Pipelines,  specifies for return value :
**
**	-> The exit status shall be the exit status of the last command
**	specified in the pipeline (except when ! is the first argument)
**
**	and for the commands to wait :
**
**	-> If the pipeline is not in the background (see Asynchronous Lists),
**	the shell shall wait for the last command specified in the pipeline to
**	complete, and may also wait for all commands to complete.
*/

static void		wait_all_child_process(
					t_data *data,
					t_params_list *params_list)
{
	waitpid(params_list->pid, &data->current_job->job_return_value, WUNTRACED);
	data->last_cmd_status = data->current_job->job_return_value;
	if (signal_stopped_child_management(data, params_list) == 0)
	{
		while (waitpid(-(params_list->pgid), NULL, 0) > -1)
			continue ;
	}
}

static void		foreground_last_command_ending(
					t_data *data,
					t_params_list *params_list,
					int sync_pfd[2])
{
	char		buf;

	close(sync_pfd[1]);
	read(sync_pfd[0], &buf, 1);
	tcsetpgrp(0, params_list->pgid);
	command_term_and_sig_configuration(data);
	close(sync_pfd[0]);
	wait_all_child_process(data, params_list);
	shell_term_and_sig_configuration(data);
	tcsetpgrp(1, getpid());
}

int				last_command(
					t_data *data,
					t_params_list *params_list,
					int sync_pfd[2])
{
	params_list->pgid = params_list->previous->pgid;
	params_list->pid = fork();
	if (params_list->pid == 0)
		set_and_exec_last_command(data, params_list, sync_pfd);
	else
	{
		close(params_list->previous->pfd[0]);
		close(params_list->previous->pfd[1]);
		params_list->pgid = params_list->previous->pgid;
		if (data->current_job->background_job == 0)
			foreground_last_command_ending(data, params_list, sync_pfd);
		else
		{
			close(sync_pfd[0]);
			close(sync_pfd[1]);
			if (data->current_job->subshell_job == 0)
			{
				load_job_control_informations_in_data(data, params_list);
				display_job_number_and_pid(data);
			}
			else
				wait_all_child_process(data, params_list);
		}
	}
	return (0);
}

/*
**	The function :
**
**		waitpid(params_list->pid, &data->last_cmd_status, 0);
**
**	loads the exit status of the end of the pipe when :
**
**		while (waitpid(-(params_list->pgid), NULL, WNOHANG) != -1)
**			continue ;
**
**	kill zombies and wait for all commands to have completed
*/
