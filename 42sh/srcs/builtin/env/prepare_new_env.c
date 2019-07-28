/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_new_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:54:59 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 03:55:56 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "env.h"

void						split_variable(
									t_data *data,
									t_local_variables *temp,
									int env_index)
{
	char					**ret_strsplit;

	ret_strsplit = ft_strsplit(data->env[env_index], '=');
	temp->variable_name = ret_strsplit[0];
	temp->variable_value = ret_strsplit[1];
	free(ret_strsplit);
}

static t_local_variables	*create_env_list(
									t_params_list *params_list,
									int *param_index)
{
	t_local_variables		*env_list;
	char					**ret_strsplit;

	if (ft_strchr(params_list->params[*param_index], '=') == NULL)
		return (NULL);
	if (!(env_list = (t_local_variables *)malloc(sizeof(t_local_variables))))
		exit(-1);
	env_list->next = NULL;
	ret_strsplit = ft_strsplit(params_list->params[*param_index], '=');
	env_list->variable_name = ret_strsplit[0];
	env_list->variable_value = ret_strsplit[1];
	free(ret_strsplit);
	return (env_list);
}

static void					change_env_list(
									t_local_variables *temp,
									char **ret_strsplit,
									int *param_index)
{
	if (ft_strcmp(temp->variable_name, ret_strsplit[0]) == 0)
	{
		free(ret_strsplit[0]);
		free(temp->variable_value);
		temp->variable_value = ret_strsplit[1];
	}
	else
	{
		if (!(temp->next = (t_local_variables *)
						malloc(sizeof(t_local_variables))))
			exit(-1);
		temp = temp->next;
		temp->variable_name = ret_strsplit[0];
		temp->variable_value = ret_strsplit[1];
		temp->next = NULL;
	}
	free(ret_strsplit);
	(*param_index)++;
}

static t_local_variables	*export_new_variables_to_list(
									t_params_list *params_list,
									int *param_index,
									t_local_variables *env_list)
{
	t_local_variables		*temp;
	char					**ret_strsplit;

	if (env_list == NULL)
		env_list = create_env_list(params_list, param_index);
	if (env_list == NULL)
		return (NULL);
	while (params_list->params[*param_index]
			&& ft_strchr(params_list->params[*param_index], '=') != NULL)
	{
		temp = env_list;
		ret_strsplit = ft_strsplit(params_list->params[*param_index], '=');
		while (temp->next != NULL)
		{
			if (ft_strcmp(ret_strsplit[0], temp->variable_name) == 0)
				break ;
			temp = temp->next;
		}
		change_env_list(temp, ret_strsplit, param_index);
	}
	return (env_list);
}

int							prepare_new_env(
									t_data *data,
									t_env_variables *env_vars,
									t_params_list *params_list)
{
	t_local_variables	*env_list;

	env_list = NULL;
	if (params_list->params[env_vars->param_index] == NULL)
		return (1);
	if (env_vars->option_i == 0 && data->env != NULL && data->env[0] != NULL)
		env_list = export_env_to_list(data, env_list);
	env_list = export_new_variables_to_list(params_list, &env_vars->param_index,
					env_list);
	convert_list_to_ptr_on_string(env_list, &env_vars->new_env);
	return (0);
}
