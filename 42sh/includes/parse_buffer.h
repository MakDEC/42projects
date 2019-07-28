/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_buffer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:20:46 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 01:22:39 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BUFFER_H
# define PARSE_BUFFER_H

# include "data_struct.h"

/*
**			-> Special chars functions
*/

int					special_char(char **buf, t_parse_vars *vars,
							t_data *data);

int					backslash_parsing(t_data *data, t_parse_vars *vars,
							char **buf);
int					dollar_parsing(t_data *data, t_parse_vars *vars,
							char **buf);
int					dquote(t_data *data, t_parse_vars *vars, char **buf);
int					esp_parsing(t_data *data, t_parse_vars *vars, char **buf);
int					left_rafter(t_data *data, t_parse_vars *vars, char **buf);
int					pipe_parsing(t_data *data, t_parse_vars *vars,
							char **buf);
int					right_rafter(t_data *data, t_parse_vars *vars, char **buf);
int					semicolon(t_data *data, t_parse_vars *vars, char **buf);
int					space_parsing(t_data *data, t_parse_vars *vars, char **buf);
int					squote(t_data *data, t_parse_vars *vars, char**buf);
int					tild(t_data *data, t_parse_vars *vars, char **buf);
int					prepare_heredoc(t_data *data, char *ref, char **buff,
						t_parse_vars *vars);

/*
**				-> Redirections functions
*/

int					absoluth_path_output_redirection(char **buf,
							t_parse_vars *vars, t_redirection *temp);
int					set_redirected_fd(char **buf, t_parse_vars *vars,
							t_redirection *temp);
int					set_input_redirection_case(char **buf, int j,
							t_parse_vars *vars, int double_rafter);
int					rafter_check_next_char(char **buf, t_parse_vars *vars);

/*
**				-> Redirections memory management
*/

t_redirection		*set_temp_case(t_parse_vars *vars);
t_redirection		*create_redirection_case(void);
t_redirection		*add_variable(char **buf, t_parse_vars *vars,
							t_redirection *temp);
t_redirection		*set_temp(t_redirection *temp, t_parse_vars *vars);
t_redirection		*set_redirection(char **buf, t_parse_vars *vars,
						int double_rafter, t_redirection *temp);

/*
**				 -> Variables Management
*/

int					check_from_env(t_parse_vars *vars);
t_parse_vars		*prepare_parsing_structure_variables(t_parse_vars *vars,
							t_data *data);
void				new_buffers_list_in_parsing_struct(t_parse_vars *vars);

/*
**				-> Params Management
*/

void				concat_param(t_parse_vars *vars);
void				concat_result(t_params *params, char *buffer);
void				new_param(t_params *params);
void				export_command_to_logical_tree(t_data *data,
							t_params *begin, t_parse_vars *vars);

/*
**				-> Logical architecture memory management
*/

void				create_full_job_architecture(t_data *data,
							t_parse_vars *vars);
t_and_list			*create_and_list(void);
t_pipe_line_data	*create_pipe_line_data_case(void);
t_params_list		*create_params_list_case(void);

void				clear_and_list(t_data *data);

/*
**				Others
*/

int					sigint_management(t_parse_vars *vars);

#endif
