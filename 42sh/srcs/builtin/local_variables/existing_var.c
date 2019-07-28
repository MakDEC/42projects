/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 04:03:07 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 04:05:43 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"

static int				overwrite_parameter(
							t_params_list *params_list)
{
	if (params_list->params[1][0] < '0' && params_list->params[1][0] > '1')
	{
		ft_putstr_fd("Second argument (overwrite) must be inexistant,\
				0 or 1\n", params_list->fd[2]);
		return (1);
	}
	else if (params_list->params[1][0] == 0)
	{
		ft_putstr_fd("This variable already exist,\
				and the overwrite is set to 0\n", params_list->fd[2]);
		return (1);
	}
	return (0);
}

void					existing_var(
							t_local_variables *vars,
							char *var,
							char *value,
							t_params_list *params_list)
{
	if (params_list->params[1] != NULL)
	{
		if (overwrite_parameter(params_list) != 0)
		{
			ft_bzero(value, ft_strlen(value));
			free(value);
			ft_bzero(var, ft_strlen(var));
			free(var);
			return ;
		}
	}
	if (vars->variable_value != NULL)
	{
		ft_bzero(vars->variable_value, ft_strlen(vars->variable_value));
		free(vars->variable_value);
	}
	vars->variable_value = value;
	ft_bzero(var, ft_strlen(var));
	free(var);
}
