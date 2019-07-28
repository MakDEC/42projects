/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_local_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 23:47:15 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 04:11:04 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "builtin.h"
#include "libft.h"

static void				create_new_var(
							t_local_variables *vars,
							char *var,
							char *value)
{
	if (!(vars->next = (t_local_variables *)malloc(sizeof(t_local_variables))))
		exit(-1);
	vars = vars->next;
	vars->next = NULL;
	vars->variable_name = var;
	vars->variable_value = value;
}

void					create_local_variables_list(
							t_data *data,
							char *var,
							char *value)
{
	if (!(data->local_variables = (t_local_variables*)malloc(
					sizeof(t_local_variables))))
		exit(-1);
	data->local_variables->next = NULL;
	data->local_variables->variable_name = var;
	data->local_variables->variable_value = value;
}

static void				set_variable_values(
							t_params_list *params_list,
							char **var,
							char **value,
							int *i)
{
	i[0] = 0;
	while (params_list->params[0][i[0]] != '=')
		i[0]++;
	*var = ft_strnew(i[0]);
	ft_strncpy(*var, params_list->params[0], i[0]);
	*value = ft_strdup(&params_list->params[0][i[0] + 1]);
}

int						local_variables_builtin(
							t_data *data,
							t_params_list *params_list)
{
	int					i;
	t_local_variables	*vars;
	char				*var;
	char				*value;

	set_variable_values(params_list, &var, &value, &i);
	vars = data->local_variables;
	if (data->local_variables == NULL)
		create_local_variables_list(data, var, value);
	else
	{
		while (vars->next != NULL && (ft_strncmp(var,
					vars->variable_name, i) != 0
					|| vars->variable_name[i] != 0))
			vars = vars->next;
		if (ft_strncmp(var, vars->variable_name, i) != 0
					|| vars->variable_name[i] != 0)
			create_new_var(vars, var, value);
		else
			existing_var(vars, var, value, params_list);
	}
	return (0);
}
