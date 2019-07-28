/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:07:57 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 18:33:48 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtin.h"

int		check_builtin(
			t_data *data,
			t_params_list *params_list)
{
	if (ft_strcmp(params_list->params[0], "exit") == 0)
		return (exit_builtin(data, params_list));
	else if (ft_strcmp(params_list->params[0], "echo") == 0)
		return (echo_builtin(params_list));
	else if (ft_strcmp(params_list->params[0], "jobs") == 0)
		return (jobs(data));
	else if (ft_strcmp(params_list->params[0], "fg") == 0)
		return (fg_builtin(data, params_list));
	else if (ft_strcmp(params_list->params[0], "cd") == 0)
	{
		cd_builtin(data, params_list);
		return (0);
	}
	else if (ft_strchr(params_list->params[0], '=') != NULL)
		return (local_variables_builtin(data, params_list));
	else if (ft_strcmp(params_list->params[0], "env") == 0
			|| ft_strcmp(params_list->params[0], "setenv") == 0
			|| ft_strcmp(params_list->params[0], "unsetenv") == 0)
		return (env_input(data, params_list));
	return (-1);
}
