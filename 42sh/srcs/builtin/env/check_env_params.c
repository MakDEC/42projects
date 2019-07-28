/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:58:33 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 02:28:13 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"
#include "env.h"

static int	print_env_usage(t_params_list *params_list,
			char wrong_option)
{
	ft_putstr_fd("env: illegal option -- ", params_list->fd[2]);
	ft_putchar_fd(wrong_option, params_list->fd[2]);
	ft_putstr_fd("\nusage : env [-i] [name=value ...]",
			params_list->fd[2]);
	ft_putendl_fd(" [utility [argument ...]]", params_list->fd[2]);
	return (-1);
}

static int	check_env_options(
					t_params_list *params_list,
					t_env_variables *env_vars)
{
	int		string_index;

	env_vars->option_i = 0;
	env_vars->param_index--;
	while (params_list->params[++env_vars->param_index]
			&& params_list->params[env_vars->param_index][0] == '-')
	{
		if (ft_strcmp(params_list->params[env_vars->param_index], "--") == 0)
		{
			env_vars->param_index++;
			break ;
		}
		string_index = 0;
		while (params_list->params[env_vars->param_index][++string_index])
		{
			if (params_list->params[env_vars->param_index][string_index] != 'i')
				return (print_env_usage(params_list, params_list->params[
							env_vars->param_index][string_index]));
			else
				env_vars->option_i = 1;
		}
	}
	return (env_vars->option_i);
}

int			check_env_params(t_data *data,
				t_env_variables *env_vars,
				t_params_list *params_list)
{
	if (check_env_options(params_list, env_vars) == -1)
		return (-1);
	prepare_new_env(data, env_vars, params_list);
	return (0);
}
