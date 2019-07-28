/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:42:14 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 01:14:02 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# include <termios.h>
# include "parse_struct.h"
# include <signal.h>

/*
** 		Local Variables Structure, content the local variables name,
**		the associated value and a pointer to the next case
*/

typedef struct					s_local_variables
{
	char						*variable_name;
	char						*variable_value;
	struct s_local_variables	*next;
}								t_local_variables;

/*
**		Termcaps structure, content all needed termcaps instructions
*/

typedef struct					s_termcaps
{

	char						*clear_down;
	char						*restor_cursor;
	char						*saving_cursor;
	char						*curs_upper_left;
	char						*curs_up;
	char						*curs_down;
	char						*curs_ri;
	char						*curs_lef;
	char						*curs_line_begin;
	char						*scroll_up;
	char						*absoluth_cursor_replace;
}								t_termcaps;

/*
**		History chain
*/

typedef struct					s_history
{
	struct s_bufstock			*buffers;
	int							nbr;
	struct s_history			*previous;
	struct s_history			*next;
}								t_history;

typedef struct					s_hash_tab
{
	struct s_hash_tab			*hash_tab[95];
	char						*name;
	char						*path;
}								t_hash_tab;

/*
** 		Data Structure
*/

typedef struct					s_data
{
	char						**env;

	t_and_list					*and_list_begin;

	t_jobs						*current_job;

	t_jobs						*job_control;

	t_jobs						*back_current_job;

	t_jobs						*back_previous_job;

	int							screen_width;
	int							prompt_size;
	int							line_nbr;

	char						*home;
	char						*oldpwd;
	char						*pwd;
	char						*children_shell_level;
	char						*clipboard;

	int							exit_status;

	int							last_cmd_status;

	struct s_hash_tab			*hash_begin;

	struct s_local_variables	*local_variables;

	struct s_termcaps			*termcaps;

	struct s_history			*history;

	struct termios				original_term_config;
	struct termios				intern_term_config;

	int							(*parsing_functions[96])(struct s_data *data,
										t_parse_vars *vars, char **buf);
}								t_data;

#endif
