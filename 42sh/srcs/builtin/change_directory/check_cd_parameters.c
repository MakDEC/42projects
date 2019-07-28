/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cd_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:41:11 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 05:18:23 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "cd.h"

static int	check_home_from_env(
					t_data *data,
					char **temp)
{
	int		i;

	i = check_env(data->env, "HOME");
	if (data->env[i] != NULL)
	{
		temp[0] = ft_strdup(&data->env[i][5]);
		return (1);
	}
	return (0);
}

static int	analyse_options_loop(
					int *mode,
					int directory_index,
					t_params_list *params_list)
{
	int		options_index;

	options_index = 0;
	while (params_list->params[directory_index][++options_index] != 0)
	{
		if (params_list->params[directory_index][options_index] == 'P')
			*mode = 1;
		else if (params_list->params[directory_index][options_index] == 'L')
			*mode = 0;
		else
		{
			cd_option_error(params_list,
					params_list->params[directory_index][options_index]);
			return (-1);
		}
	}
	return (0);
}

static int	check_cd_options(
					int *mode,
					t_params_list *params_list)
{
	int		directory_index;

	directory_index = 0;
	while (params_list->params[++directory_index]
			&& params_list->params[directory_index][0] == '-')
	{
		if (ft_strcmp(params_list->params[directory_index], "-") == 0)
			return (directory_index);
		else if (ft_strcmp(params_list->params[directory_index], "--") == 0)
		{
			directory_index++;
			break ;
		}
		else if (analyse_options_loop(mode, directory_index, params_list) == -1)
			return (-1);
	}
	return (directory_index);
}

static int	set_directory_to_home(
					t_data *data,
					char **directory,
					t_params_list *params_list)
{
	if (check_home_from_env(data, directory) == 1)
		return (1);
	else if (data->home != NULL)
	{
		directory[0] = ft_strdup(data->home);
		return (1);
	}
	else
		ft_putstr_fd("HOME isn't set, cd failed\n",
				params_list->fd[2]);
	return (-1);
}

int			cd_check_special_params(
					t_data *data,
					t_cd_variables *cd_vars,
					t_params_list *params_list)
{
	cd_vars->mode = 0;
	cd_vars->directory_position = check_cd_options(&cd_vars->mode, params_list);
	if (cd_vars->directory_position < 1)
		return (-1);
	if (params_list->params[cd_vars->directory_position] == NULL)
		return (set_directory_to_home(data, &cd_vars->directory, params_list));
	else if (ft_strcmp(params_list->params[cd_vars->directory_position],
				"-") == 0)
	{
		if (data->oldpwd != NULL)
		{
			cd_vars->directory = ft_strdup(data->oldpwd);
			return (1);
		}
		ft_putstr_fd("OLDPWD is not set, cd - impossible\n",
				params_list->fd[2]);
		return (-1);
	}
	return (0);
}
