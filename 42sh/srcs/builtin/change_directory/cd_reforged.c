/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_reforged.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:16:20 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 05:23:15 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"
#include "env.h"
#include "libft.h"

static void		prepare_env_variables(
						t_data *data,
						t_cd_variables *cd_vars,
						t_params_list *params_list)
{
	char		*oldpwd;

	oldpwd = NULL;
	if (data->oldpwd != NULL)
		oldpwd = ft_strdup(data->pwd);
	if (cd_vars->mode == 1)
	{
		free(cd_vars->directory);
		cd_vars->directory = getcwd(NULL, 0);
	}
	change_env_variables(data, cd_vars->directory, oldpwd, params_list);
}

static int		change_directory(
						t_data *data,
						t_cd_variables *cd_vars,
						t_params_list *params_list)
{
	struct stat	filestat;

	if (chdir(cd_vars->directory) != 0)
	{
		if (stat(cd_vars->directory, &filestat) == -1)
			ft_putstr_fd("cd: no such file or directory: ",
					params_list->fd[2]);
		else
		{
			if (filestat.st_mode & S_IFDIR)
				ft_putstr_fd("cd: permission denied: ",
						params_list->fd[2]);
			else
				ft_putstr_fd("cd: not a directory: ",
						params_list->fd[2]);
		}
		ft_putendl_fd(cd_vars->directory, params_list->fd[2]);
		free(cd_vars->directory);
		return (-1);
	}
	else
		prepare_env_variables(data, cd_vars, params_list);
	return (0);
}

int				cd_builtin(
						t_data *data,
						t_params_list *params_list)
{
	t_cd_variables	cd_vars;
	int				ret_spec_params;

	cd_vars.directory = NULL;
	if ((ret_spec_params = cd_check_special_params(data, &cd_vars,
						params_list)) != 1)
	{
		if (ret_spec_params == -1)
			return (-1);
		else if (params_list->params[cd_vars.directory_position][0] == '/')
			cd_vars.directory = prepare_directory_from_absoluth_path(&cd_vars,
						params_list);
		else
			cd_vars.directory = prepare_directory_from_relative_path(data,
						&cd_vars, params_list);
	}
	if (cd_vars.directory != NULL)
		return (change_directory(data, &cd_vars, params_list));
	return (-1);
}
