/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe_line_cases.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:40:10 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:39:22 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"

t_params_list				*create_params_list_case(void)
{
	t_params_list		*new_case;

	if (!(new_case = (t_params_list *)malloc(sizeof(t_params_list))))
		exit(-1);
	new_case->next = NULL;
	new_case->previous = NULL;
	new_case->params = NULL;
	new_case->redirections = NULL;
	new_case->cmd_path = NULL;
	new_case->pid = -1;
	new_case->pgid = -1;
	new_case->argc = 0;
	return (new_case);
}

t_pipe_line_data			*create_pipe_line_data_case(void)
{
	t_pipe_line_data		*new_case;

	if (!(new_case = (t_pipe_line_data *)malloc(sizeof(t_pipe_line_data))))
		exit(-1);
	new_case->next = NULL;
	new_case->pl_exit_status = 0;
	new_case->pipe_line_begin = create_params_list_case();
	new_case->pipe_line_current_case = new_case->pipe_line_begin;
	return (new_case);
}

t_and_list					*create_and_list(void)
{
	t_and_list		*new_case;

	if (!(new_case = (t_and_list *)malloc(sizeof(t_and_list))))
		exit(-1);
	new_case->and_list_next = NULL;
	new_case->or_list_begin = create_pipe_line_data_case();
	new_case->or_list_current_case = new_case->or_list_begin;
	return (new_case);
}

t_jobs						*create_job_data_architecture(void)
{
	t_jobs			*new_case;

	if (!(new_case = (t_jobs *)malloc(sizeof(t_jobs))))
	{
		ft_putstr_fd("42sh: malloc call failed, shell will now exit\n", 2);
		exit(-1);
	}
	new_case->and_list_begin = create_and_list();
	new_case->subshell_pid = -1;
	new_case->subshell_job = 0;
	new_case->shell_job_number = -1;
	new_case->pid_to_check = -1;
	new_case->pgid_to_wait = -1;
	new_case->background_job = 0;
	new_case->job_return_value = -1;
	new_case->logical_job = 0;
	new_case->full_buf = NULL;
	new_case->next = NULL;
	new_case->previous = NULL;
	return (new_case);
}

void						create_full_job_architecture(
									t_data *data,
									t_parse_vars *vars)
{
	data->current_job = create_job_data_architecture();
	vars->current_job = data->current_job;
	vars->and_list_begin = data->current_job->and_list_begin;
	vars->and_list_case = vars->and_list_begin;
	vars->pipe_line_data = vars->and_list_begin->or_list_begin;
	vars->params_list_case = vars->pipe_line_data->pipe_line_begin;
}
