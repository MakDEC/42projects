/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_right_env_function.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:58:28 by aanger            #+#    #+#             */
/*   Updated: 2019/04/09 18:16:53 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"
#include "builtin.h"

int				env_input(t_data *data, t_params_list *params_list)
{
	if (ft_strcmp(params_list->params[0], "env") == 0)
		return (ft_env(data, params_list));
	else if (ft_strcmp(params_list->params[0], "unsetenv") == 0)
		return (ft_unsetenv(data, params_list));
	else if (ft_strcmp(params_list->params[0], "setenv") == 0)
		return (ft_setenv(data, params_list));
	return (1);
}
