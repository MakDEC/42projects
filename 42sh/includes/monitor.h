/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:59:36 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 01:20:53 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

# include "data_struct.h"

/*
**			-> Configuration functions
*/

void			command_term_and_sig_configuration(t_data *data);
void			shell_term_and_sig_configuration(t_data *data);

/*
**			-> Executions functions
*/

int				background_simple_command(t_data *data,
						t_params_list *params_list, int sync_pfd[2]);
int				check_env(char **env, char *var);
int				foreground_simple_command(t_data *data,
						t_params_list *params_list, int sync_pfd[2]);
int				fork_for_simple_command(t_data *data,
						t_params_list *params_list);
void			load_children_shell_level(t_data *data);
int				pipeline_execution(t_data *data, t_pipe_line_data *pl_data);
int				set_and_exec_simple_command(t_data *data,
						t_params_list *params_list, int	sync_pfd[2]);
int				simple_command(t_data *data, t_params_list *params_list);
void			subshell_execution(t_data *data);

/*
**			-> Hash Table functions
*/

void			multi_path(t_hash_tab *temp, char *current_path,
						char *name, int size_to_malloc);

/*
**			-> Job control functions
*/

void			add_job_to_list(t_data *data);
void			completed_jobs_verification(t_data *data);
void			display_job_number_and_pid(t_data *data);
void			display_job_status(t_data *data, t_jobs *job_case);
void			export_command_buf(t_data *data);
t_jobs			*finish_job_and_free_memory(t_data *data, t_jobs *job_case);
void			kill_zombies_process(pid_t pgid);
void			load_job_control_informations_in_data(t_data *data,
						t_params_list *params_list);
void			new_background_current_job(t_data *data);

/*
**			-> Interactive Monitor functions
*/

void			ft_prompt(t_data *data);
int				reader(t_data *data, char **rslt);
int				parser(t_data *data, char **buf);
int				job_loader(t_data *data);
int				signal_stopped_child_management(t_data *data,
						t_params_list *params_list);
void			clear_current_case(t_data *data);

/*
**			-> Logical monitors functions
*/

int				and_logical_monitor(t_data *data, t_and_list *and_list);
int				or_logical_monitor(t_data *data, t_pipe_line_data *or_list);

/*
**			-> Pipe lines execution functions
*/

int				first_command(t_data *data, t_params_list *params_list,
					int sync_pfd[2]);
int				intermediate_command(t_data *data, t_params_list *params_list,
					int sync_pfd[2]);
int				last_command(t_data *data, t_params_list *params_list,
					int sync_pfd[2]);

/*
**			-> Redirections functions
*/

int				apply_redirections(t_params_list *params_list);
void			clear_redirections(t_params_list *node);
int				prepare_all_redirections(t_params_list *params_list);
int				prepare_output_redirections(t_params_list *node,
						t_redirection *temp);
int				prepare_input_redirections(t_redirection *node);

/*
**			-> Validity verification and preparation functions
*/

int				check_pipeline_commands_validity(t_data *data,
						t_params_list *params_list);
int				check_builtin(t_data *data, t_params_list *params_list);
void			free_hash_tab(t_hash_tab *temp);
int				ft_invalid_com(t_params_list *params_list, char *buf);
int				prepare_verify_and_exec_pipeline(t_data *data,
						t_pipe_line_data *pl_data);
t_hash_tab		*search_in_hash_tab(t_hash_tab *temp, char *name);

void			clear_local_variables(t_local_variables *vars);

#endif
