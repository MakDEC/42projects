/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:39:28 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 20:16:41 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "parse_buffer.h"
#include "libft.h"

static int		pipe_parsing_error(void)
{
	ft_putstr_fd("Parsing problem with a pipe\n", 2);
	return (1);
}

static int		check_errors_after_pipe(
					char **buf,
					int index)
{
	static char	*errors_chars = "|&;";
	int			ec_index;

	ec_index = -1;
	while (buf[0][++index] && buf[0][index] == ' ')
		continue ;
	while (errors_chars[++ec_index])
		if (errors_chars[ec_index] == buf[0][index])
			return (pipe_parsing_error());
	return (0);
}

int				or_logical_operator_ending(
					t_data *data,
					t_parse_vars *vars)
{
	data->current_job->logical_job = 0;
	vars->pipe_line_data->next = create_pipe_line_data_case();
	vars->pipe_line_data = vars->pipe_line_data->next;
	vars->and_list_case->or_list_current_case = vars->pipe_line_data;
	vars->pipe_line_data->pipe_line_current_case = vars->
		pipe_line_data->pipe_line_begin;
	vars->params_list_case = vars->pipe_line_data->pipe_line_begin;
	return (0);
}

static int		pipe_parsing_errors(t_parse_vars *vars, char **buf)
{
	int		or_logical_operator;

	or_logical_operator = 0;
	vars->i++;
	if (buf[0][vars->i] == '|')
	{
		or_logical_operator = 1;
		vars->i++;
	}
	if (vars->redirections == NULL && vars->begin->buf == NULL)
		return (2);
	if (check_errors_after_pipe(buf, vars->i - 1) != 0)
		return (2);
	return (or_logical_operator);
}

int				pipe_parsing(
					t_data *data,
					t_parse_vars *vars,
					char **buf)
{
	int			or_operator;

	concat_param(vars);
	if ((or_operator = pipe_parsing_errors(vars, buf)) > 1)
		return (pipe_parsing_error());
	export_command_to_logical_tree(data, vars->begin, vars);
	new_buffers_list_in_parsing_struct(vars);
	vars->i++;
	if (or_operator == 1)
		return (or_logical_operator_ending(data, vars));
	vars->params_list_case->next = create_params_list_case();
	vars->params_list_case->next->previous = vars->params_list_case;
	vars->params_list_case = vars->params_list_case->next;
	vars->pipe_line_data->pipe_line_current_case = vars->params_list_case;
	return (0);
}
