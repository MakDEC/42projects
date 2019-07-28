/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tild_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:17:09 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 20:17:34 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "parse_buffer.h"
#include <env.h>
#include "libft.h"

int				tild(t_data *data, t_parse_vars *vars, char **buf)
{
	(void)buf;
	concat_param(vars);
	if (data->env[check_env(data->env, "HOME")] != NULL)
		ft_strcpy(vars->temp, &data->env[check_env(data->env, "HOME")][5]);
	else if (data->home != NULL)
		ft_strcpy(vars->temp, data->home);
	else
		return (0);
	vars->j = ft_strlen(vars->temp);
	concat_param(vars);
	vars->i++;
	return (0);
}
