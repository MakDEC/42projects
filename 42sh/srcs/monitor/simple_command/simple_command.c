/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:31:20 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 02:54:35 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"

int		simple_command(
			t_data *data,
			t_params_list *params_list)
{
	int		ret_check_builtin;

	if ((ret_check_builtin = check_builtin(data, params_list)) != -1)
	{
		data->last_cmd_status = ret_check_builtin;
		return (ret_check_builtin);
	}
	return (fork_for_simple_command(data, params_list));
}
