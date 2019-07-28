/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:22:42 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 02:58:27 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include "monitor.h"

static void			free_new_env(
							char **new_env)
{
	int			index;

	if (!(new_env))
		return ;
	index = -1;
	while (new_env[++index] != NULL)
	{
		if (new_env[index] != NULL)
			free(new_env[index]);
	}
	free(new_env);
}

static void			change_params(
							t_params_list *params_list,
							int param_index)
{
	int		index;

	index = 0;
	while (params_list->params[param_index] != NULL)
	{
		free(params_list->params[index]);
		params_list->params[index] = params_list->params[param_index];
		params_list->params[param_index] = NULL;
		index++;
		param_index++;
	}
	while (params_list->params[index] != NULL)
	{
		free(params_list->params[index]);
		params_list->params[index] = NULL;
		index++;
	}
}

static int			execve_with_new_env(
							t_data *data,
							t_env_variables *env_vars,
							t_params_list *params_list)
{
	char	**back_up_env;

	change_params(params_list, env_vars->param_index);
	back_up_env = data->env;
	data->env = env_vars->new_env;
	if (prepare_all_redirections(params_list) != 0)
		return (1);
	if (check_pipeline_commands_validity(data, params_list) != 0)
		return (1);
	if (params_list->next == NULL)
		simple_command(data, params_list);
	else
		pipeline_execution(data, NULL);
	data->env = back_up_env;
	return (0);
}

static void			operate_good_end(
							t_data *data,
							t_env_variables *env_vars,
							t_params_list *params_list)
{
	int			i;

	if (params_list->params[env_vars->param_index] == NULL)
	{
		if (env_vars->new_env == NULL)
			return ;
		i = -1;
		while (env_vars->new_env[++i] != NULL)
			ft_putendl(env_vars->new_env[i]);
	}
	else
		execve_with_new_env(data, env_vars, params_list);
	free_new_env(env_vars->new_env);
}

int					ft_env(
							t_data *data,
							t_params_list *params_list)
{
	t_env_variables	env_vars;

	env_vars.new_env = NULL;
	env_vars.param_index = 1;
	if (params_list->params[1] == NULL)
	{
		print_env(data, params_list);
		return (0);
	}
	while (params_list->params[env_vars.param_index] != NULL
			&& ft_strcmp(params_list->params[env_vars.param_index], "env") == 0)
		env_vars.param_index++;
	check_env_params(data, &env_vars, params_list);
	while (params_list->params[env_vars.param_index] != NULL
			&& ft_strcmp(params_list->params[env_vars.param_index], "env") == 0)
		env_vars.param_index++;
	operate_good_end(data, &env_vars, params_list);
	return (0);
}
