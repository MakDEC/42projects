/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:44:27 by aanger            #+#    #+#             */
/*   Updated: 2019/07/12 23:42:26 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOBS_STRUCT_H
# define JOBS_STRUCT_H

# include <sys/types.h>

typedef struct					s_params_list
{
	char						**params;
	int							argc;

	int							pfd[2];

	pid_t						pid;
	pid_t						pgid;

	char						*cmd_path;

	struct s_redirection		*redirections;

	int							fd[10];

	struct s_params_list		*next;
	struct s_params_list		*previous;
}								t_params_list;

typedef struct					s_pipe_line_data
{
	t_params_list				*pipe_line_begin;
	t_params_list				*pipe_line_current_case;

	int							pl_exit_status;

	struct s_pipe_line_data		*next;
}								t_pipe_line_data;

typedef struct					s_and_list
{
	t_pipe_line_data			*or_list_begin;
	t_pipe_line_data			*or_list_current_case;
	struct s_and_list			*and_list_next;
}								t_and_list;

typedef struct					s_jobs
{
	t_and_list					*and_list_begin;

	int							subshell_pid;

	int							shell_job_number;

	int							pid_to_check;

	int							pgid_to_wait;

	int							logical_job;

	int							background_job;

	int							subshell_job;

	int							job_return_value;

	char						*full_buf;

	struct s_jobs				*next;

	struct s_jobs				*previous;
}								t_jobs;

#endif
