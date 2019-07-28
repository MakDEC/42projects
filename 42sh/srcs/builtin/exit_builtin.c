/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:08:15 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:01 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"

static int	check_exit_params(t_params_list *params_list)
{
	int		index;

	if (params_list->params[1] == NULL)
		return (0);
	if (params_list->params[2] != NULL && params_list->fd[2] >= 0)
	{
		ft_putstr_fd("exit builtin : Too many arguments\n",
				params_list->fd[2]);
		ft_putstr_fd("usage: exit [EXIT_STATUS]\n", params_list->fd[2]);
	}
	index = -1;
	if (params_list->params[1][0] == '-')
		++index;
	while (params_list->params[1][++index])
		if (ft_isdigit(params_list->params[1][index]) != 1)
		{
			if (params_list->fd[2] >= 0)
				ft_putstr_fd("exit builtin : exit status must be a number\n",
						params_list->fd[2]);
			return (1);
		}
	return (0);
}

int			exit_builtin(t_data *data, t_params_list *params_list)
{
	if (check_exit_params(params_list) != 0)
		return (1);
	if (params_list->params[1] == NULL)
		data->exit_status = data->last_cmd_status;
	else
		data->exit_status = (unsigned char)ft_atoi(params_list->params[1]);
	return (0);
}
