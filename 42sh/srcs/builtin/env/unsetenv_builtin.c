/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:02:51 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 00:09:10 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"
#include "env.h"

static int		unsetenv_no_var_error(
				t_params_list *params_list)
{
	ft_putstr_fd(params_list->params[1],
			params_list->fd[2]);
	ft_putstr_fd(" environment variable was not found\n",
			params_list->fd[2]);
	return (1);
}

void			remove_hash_table(
				t_data *data)
{
	free_hash_tab(data->hash_begin);
	data->hash_begin = NULL;
}

static void		unsetenv_usage(
				t_params_list *params_list)
{
	ft_putstr_fd("usage: unsetenv [Variable Name]\n",
			params_list->fd[2]);
}

static int		check_unsetenv_params(
				t_params_list *params_list)
{
	if (params_list->params[1] == NULL)
	{
		ft_putstr_fd("unsetenv builtin: Too few arguments\n",
				params_list->fd[2]);
		unsetenv_usage(params_list);
		return (1);
	}
	else if (params_list->params[2] != NULL)
	{
		ft_putstr_fd("unsetenv builtin: Too many arguments\n",
				params_list->fd[2]);
		unsetenv_usage(params_list);
		return (2);
	}
	return (0);
}

int				ft_unsetenv(
					t_data *data,
					t_params_list *params_list)
{
	int		i;

	if (check_unsetenv_params(params_list) != 0)
		return (1);
	i = check_env(data->env, params_list->params[1]);
	if (data->env[i] != NULL)
	{
		ft_bzero(data->env[i], ft_strlen(data->env[i]));
		free(data->env[i]);
		while (data->env[i + 1] != NULL)
		{
			data->env[i] = data->env[i + 1];
			i++;
		}
		data->env[i] = NULL;
		ft_putstr_fd(params_list->params[1], params_list->fd[1]);
		ft_putstr_fd(" has been unset from environment\n",
				params_list->fd[1]);
		if (ft_strcmp(params_list->params[1], "PATH") == 0)
			remove_hash_table(data);
	}
	else
		return (unsetenv_no_var_error(params_list));
	return (0);
}
