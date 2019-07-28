/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:09:34 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:35:07 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "parse_buffer.h"
#include "sigint.h"
#include <signal.h>

int				analyse_char(
						char **buf,
						t_parse_vars *vars,
						t_data *data)
{
	int		ret_parsing_function;

	ret_parsing_function = 0;
	if (data->parsing_functions[(int)(buf[0][vars->i] - 32)] == NULL)
		vars->temp[vars->j++] = buf[0][vars->i++];
	else
		ret_parsing_function = data->parsing_functions[
				(int)(buf[0][vars->i] - 32)](data, vars, buf);
	if (vars->j == 4095)
		concat_param(vars);
	return (ret_parsing_function);
}

static int		parsing_loop(
						t_data *data,
						char **buf,
						t_parse_vars *vars)
{
	int		ret_read_buf;

	ret_read_buf = 0;
	while (buf[0] != NULL && buf[0][vars->i] && buf[0][vars->i] != 0)
	{
		if ((ret_read_buf = analyse_char(buf, vars, data)) != 0)
			break ;
		if (vars->params != NULL && vars->params->next != NULL)
			vars->params = vars->params->next;
	}
	return (ret_read_buf);
}

int				parser(
						t_data *data,
						char **buf)
{
	t_parse_vars	*vars;
	int				ret_read_buf;

	vars = NULL;
	vars = prepare_parsing_structure_variables(vars, data);
	ret_read_buf = parsing_loop(data, buf, vars);
	concat_param(vars);
	export_command_to_logical_tree(data, vars->begin, vars);
	free(vars);
	return (ret_read_buf);
}
