/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_validity.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:49:14 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:02:37 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "libft.h"

static int			static_check_builtin_command(
						t_params_list *params_list)
{
	if (ft_strcmp(params_list->params[0], "env") == 0)
		return (0);
	if (ft_strcmp(params_list->params[0], "setenv") == 0)
		return (0);
	if (ft_strcmp(params_list->params[0], "unsetenv") == 0)
		return (0);
	if (ft_strcmp(params_list->params[0], "cd") == 0)
		return (0);
	if (ft_strcmp(params_list->params[0], "echo") == 0)
		return (0);
	if (ft_strcmp(params_list->params[0], "exit") == 0)
		return (0);
	if (ft_strchr(params_list->params[0], '=') != NULL)
		return (0);
	return (1);
}

static int			print_acces_error(
						t_params_list *params_list)
{
	ft_putstr_fd("42sh: permission denied: ", params_list->fd[2]);
	ft_putendl_fd(params_list->params[0], params_list->fd[2]);
	return (1);
}

static int			check_absoluth_path_cmd(
						t_params_list *params_list)
{
	struct stat		filestat;

	if (stat(params_list->params[0], &filestat) == 0)
	{
		if (access(params_list->params[0], X_OK) == 0)
		{
			params_list->cmd_path = params_list->params[0];
			return (0);
		}
		else
			return (print_acces_error(params_list));
	}
	return (1);
}

static int			check_command_validity_and_fill_cmd_path(
						t_data *data,
						t_params_list *params_list)
{
	t_hash_tab		*temp;

	params_list->cmd_path = NULL;
	if (params_list->params[0] == NULL)
		return (1);
	if (static_check_builtin_command(params_list) == 0)
		return (0);
	if (ft_strchr(params_list->params[0], '/') != NULL
			&& check_absoluth_path_cmd(params_list) == 0)
		return (0);
	temp = search_in_hash_tab(data->hash_begin, params_list->params[0]);
	if (temp != NULL && temp->path != NULL)
	{
		if (access(temp->path, X_OK) == 0)
		{
			params_list->cmd_path = temp->path;
			return (0);
		}
		else
			return (print_acces_error(params_list));
	}
	ft_invalid_com(params_list, params_list->params[0]);
	data->last_cmd_status = 127;
	return (1);
}

int					check_pipeline_commands_validity(
						t_data *data,
						t_params_list *params_list)
{
	while (params_list != NULL)
	{
		if (check_command_validity_and_fill_cmd_path(data, params_list) != 0)
			return (1);
		params_list = params_list->next;
	}
	return (0);
}
