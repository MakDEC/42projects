/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:22:41 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 04:15:03 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <unistd.h>
#include <stdlib.h>

static void		set_and_exec_intermediate_command(
					t_data *data,
					t_params_list *params_list,
					int sync_pfd[2])
{
	char		buf;

	if (data->current_job->subshell_job == 0)
		while (setpgid(getpid(), params_list->pgid) != 0)
			continue ;
	else
		while (setpgid(params_list->pid, data->current_job->subshell_pid) != 0)
			continue ;
	close(sync_pfd[1]);
	read(sync_pfd[0], &buf, 1);
	close(sync_pfd[0]);
	if (check_builtin(data, params_list) != -1)
		exit(0);
	dup2(params_list->previous->pfd[0], 0);
	close(params_list->previous->pfd[0]);
	dup2(params_list->pfd[1], 1);
	close(params_list->pfd[1]);
	apply_redirections(params_list);
	execve(params_list->cmd_path, params_list->params, data->env);
}

int				intermediate_command(
					t_data *data,
					t_params_list *params_list,
					int sync_pfd[2])
{
	params_list->pgid = params_list->previous->pgid;
	pipe(params_list->pfd);
	params_list->fd[1] = params_list->pfd[1];
	params_list->pid = fork();
	if (params_list->pid == 0)
		set_and_exec_intermediate_command(data, params_list, sync_pfd);
	else
	{
		close(params_list->previous->pfd[0]);
		close(params_list->pfd[1]);
		return (0);
	}
	return (1);
}
