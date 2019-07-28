/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esp_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:59:07 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 20:43:30 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "parse_buffer.h"
#include "libft.h"

static int	simple_esp_end(
				t_data *data,
				t_parse_vars *vars)
{
	data->current_job->background_job = 1;
	vars->i++;
	return (0);
}

static int	esp_parsing_error(void)
{
	ft_putstr_fd("42sh: parsing error for &\n", 2);
	return (1);
}

int			adapt_logical_path_and_parsing_struct_variables(
				t_data *data,
				t_parse_vars *vars)
{
	data->current_job->logical_job = 1;
	vars->and_list_case->and_list_next =
		create_and_list();
	vars->and_list_case =
		vars->and_list_case->and_list_next;
	vars->pipe_line_data = vars->and_list_case->or_list_begin;
	vars->params_list_case = vars->pipe_line_data->pipe_line_begin;
	return (0);
}

int			esp_parsing(
				t_data *data,
				t_parse_vars *vars,
				char **buf)
{
	concat_param(vars);
	if (buf[0][vars->i + 1] == 0)
		return (simple_esp_end(data, vars));
	if (buf[0][vars->i + 1] != '&')
		return (esp_parsing_error());
	vars->i += 2;
	export_command_to_logical_tree(data, vars->begin, vars);
	adapt_logical_path_and_parsing_struct_variables(data, vars);
	new_buffers_list_in_parsing_struct(vars);
	return (0);
}
