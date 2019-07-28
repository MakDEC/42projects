/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:31:40 by aanger            #+#    #+#             */
/*   Updated: 2019/05/05 16:36:20 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include <stdlib.h>

void		set_data_values(t_data *data)
{
	data->prompt_size = 0;
	data->and_list_begin = NULL;
	data->current_job = 0;
	data->job_control = 0;
	data->back_current_job = NULL;
	data->back_previous_job = NULL;
	data->clipboard = NULL;
	data->home = NULL;
	data->pwd = NULL;
	data->oldpwd = NULL;
	data->children_shell_level = NULL;
	data->local_variables = NULL;
	data->history = NULL;
	data->exit_status = -1;
	data->last_cmd_status = 0;
}
