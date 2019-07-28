/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:43:58 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 01:24:49 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_STRUCT_H
# define PARSE_STRUCT_H

# include "jobs_struct.h"

/*
** 						Temporary structures
**
** 			Params Structure, content a buffer (the parameter) and
**					the next parameter position
*/

typedef struct				s_params
{
	char					*buf;
	struct s_params			*next;
}							t_params;

typedef struct				s_redirection
{
	char					*redirection;
	char					double_rafter;
	char					input_redirection;
	int						redirected_fd;
	int						redirection_fd;
	struct s_redirection	*next;
}							t_redirection;

/*
** 			Parsing Structure, content tools to turn the input into
**        variable correctly and a t_data pointer to access datas everywhere
*/
typedef struct				s_parse_vars
{
	char					temp[4097];
	int						i;
	int						j;
	struct s_params			*begin;
	struct s_params			*params;
	struct s_data			*data;
	t_jobs					*current_job;
	t_and_list				*and_list_begin;
	t_and_list				*and_list_case;
	t_pipe_line_data		*pipe_line_data;
	t_params_list			*params_list_case;
	struct s_redirection	*redirections;
}							t_parse_vars;

#endif
