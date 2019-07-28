/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_and_exec_pipeline.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 23:44:45 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 02:10:46 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stddef.h>

int			prepare_verify_and_exec_pipeline(t_data *data,
				t_pipe_line_data *pl_data)
{
	int		ret_command_line;

	pl_data->pipe_line_current_case = pl_data->pipe_line_begin;
	if (prepare_all_redirections(pl_data->pipe_line_current_case) != 0)
		return (1);
	if (check_pipeline_commands_validity(data,
					pl_data->pipe_line_current_case) != 0)
		return (1);
	if (pl_data->pipe_line_current_case->next == NULL)
		ret_command_line = simple_command(data,
				pl_data->pipe_line_current_case);
	else
		ret_command_line = pipeline_execution(data, pl_data);
	return (ret_command_line);
}
