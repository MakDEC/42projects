/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_from_env_variables.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 02:40:49 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:41:31 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"

int				check_from_env(t_parse_vars *vars)
{
	int			i;
	size_t		size;

	i = -1;
	size = ft_strlen(vars->temp);
	while (vars->data->env[++i] != NULL)
		if (ft_strncmp(vars->data->env[i], vars->temp, size) == 0)
		{
			ft_bzero(vars->temp, ft_strlen(vars->temp));
			ft_strcpy(vars->temp, &vars->data->env[i][size + 1]);
			vars->j = ft_strlen(vars->temp);
			return (0);
		}
	ft_bzero(vars->temp, vars->j);
	return (1);
}
