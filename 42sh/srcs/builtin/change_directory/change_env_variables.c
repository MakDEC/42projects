/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:25:01 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 05:18:13 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtin.h"
#include "cd.h"

static void		change_pwd(
						t_data *data,
						char *newwd,
						char **temp_params,
						t_params_list *params_list)
{
	ft_strcpy(temp_params[1], "PWD");
	temp_params[2] = newwd;
	temp_params[3] = NULL;
	ft_setenv(data, params_list);
	ft_bzero(temp_params[0], 6);
	free(temp_params[0]);
	ft_bzero(temp_params[1], 3);
	free(temp_params[1]);
	free(temp_params);
	if (data->pwd != NULL)
	{
		ft_bzero(data->pwd, ft_strlen(data->pwd));
		free(data->pwd);
	}
	data->pwd = newwd;
}

void			change_env_variables(
						t_data *data,
						char *newwd,
						char *oldwd,
						t_params_list *params_list)
{
	char	**temp_params;
	char	**backup_params;

	if (!(temp_params = (char**)malloc(sizeof(char*) * 4)))
		exit(-1);
	backup_params = params_list->params;
	temp_params[0] = ft_strdup("setenv");
	temp_params[1] = ft_strdup("OLDPWD");
	temp_params[2] = oldwd;
	temp_params[3] = NULL;
	params_list->params = temp_params;
	ft_setenv(data, params_list);
	ft_bzero(temp_params[1], 6);
	if (data->oldpwd != NULL)
	{
		ft_bzero(data->oldpwd, ft_strlen(data->oldpwd));
		free(data->oldpwd);
	}
	data->oldpwd = oldwd;
	temp_params[2] = NULL;
	change_pwd(data, newwd, temp_params, params_list);
	params_list->params = backup_params;
}
