/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:37:35 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 02:44:05 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"
#include "prerequisites.h"
#include "env.h"

static void		create_new_env_with_new_var(t_data *data,
				int i,
				t_params_list *params_list)
{
	char	**newenv;
	int		size_to_mal;

	size_to_mal = ft_strlen(params_list->params[1]) + 2;
	if (params_list->params[2] != NULL)
		size_to_mal += ft_strlen(params_list->params[2]);
	if (!(newenv = (char**)malloc(sizeof(char*) * (i + 2))))
		exit(-1);
	i = -1;
	while (data->env[++i] && data->env[i] != NULL)
		newenv[i] = data->env[i];
	free(data->env);
	if (!(newenv[i] = (char*)malloc(sizeof(char) * size_to_mal)))
		exit(-1);
	ft_bzero(newenv[i], size_to_mal);
	ft_strcat(ft_strcat(newenv[i], params_list->params[1]), "=");
	if (params_list->params[2] != NULL)
		ft_strcat(newenv[i], params_list->params[2]);
	newenv[i + 1] = NULL;
	data->env = newenv;
	if (ft_strcmp(params_list->params[1], "PATH") == 0)
	{
		remove_hash_table(data);
		create_hash_tab(data);
	}
}

static int		check_env_var_name(t_params_list *params_list)
{
	int			index;

	index = -1;
	while (params_list->params[1][++index] != 0)
	{
		if (ft_isalnum(params_list->params[1][index]) == 0
				&& params_list->params[1][index] != '_')
		{
			ft_putstr_fd("setenv builtin : environnement variables must ",
					params_list->fd[2]);
			ft_putstr_fd("contain only alphanumeric characters ",
					params_list->fd[2]);
			ft_putstr_fd("or '_'\n",
					params_list->fd[2]);
			return (1);
		}
	}
	return (0);
}

static int		check_setenv_params(t_params_list *params_list)
{
	if (check_env_var_name(params_list) != 0)
		return (1);
	if (params_list->params[2] != NULL && params_list->params[3] != NULL)
	{
		if (ft_strcmp(params_list->params[3], "0") == 0
				&& ft_strcmp(params_list->params[3], "1") == 0)
			return (0);
		if (params_list->params[4] != NULL)
			ft_putstr_fd("setenv builtin : bad numbers of arguments\n",
					params_list->fd[2]);
		ft_putstr_fd("usage : setenv [NAME] [VALUE] [overwrite_parameter \
				(0 or 1)]\n", params_list->fd[2]);
		return (1);
	}
	return (0);
}

static void		modify_existing_env_var(t_data *data,
				int i,
				t_params_list *params_list)
{
	char	*newenvvar;
	int		size_to_mall;

	size_to_mall = ft_strlen(params_list->params[1]) + 2;
	if (params_list->params[2] != NULL)
		size_to_mall += ft_strlen(params_list->params[2]);
	newenvvar = ft_strnew(size_to_mall);
	ft_bzero(newenvvar, size_to_mall);
	ft_strcat(newenvvar, params_list->params[1]);
	ft_strcat(newenvvar, "=");
	if (params_list->params[2] != NULL)
		ft_strcat(newenvvar, params_list->params[2]);
	free(data->env[i]);
	data->env[i] = newenvvar;
	if (ft_strcmp(params_list->params[1], "PATH") == 0)
	{
		remove_hash_table(data);
		create_hash_tab(data);
	}
}

int				ft_setenv(t_data *data, t_params_list *params_list)
{
	int		i;

	if (params_list->params[1] == NULL)
	{
		print_env(data, params_list);
		return (0);
	}
	if (check_setenv_params(params_list) != 0)
		return (1);
	i = check_env(data->env, params_list->params[1]);
	if (data->env[i] == NULL)
		create_new_env_with_new_var(data, i, params_list);
	else if (params_list->params[2] != NULL && params_list->params[3] != NULL
			&& params_list->params[3][0] == '0')
	{
		ft_putstr_fd(params_list->params[1], params_list->fd[2]);
		ft_putstr_fd(" already exist and overwrite param is set to 0\n",
				params_list->fd[2]);
		return (1);
	}
	else
		modify_existing_env_var(data, i, params_list);
	return (0);
}
