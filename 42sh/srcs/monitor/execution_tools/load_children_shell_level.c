/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_children_shell_level.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:53:45 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 02:57:30 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stdlib.h>

void		load_children_shell_level(
			t_data *data)
{
	int	shlvl_index;

	shlvl_index = check_env(data->env, "SHLVL");
	if (data->env[shlvl_index] != NULL)
	{
		free(data->env[shlvl_index]);
		data->env[shlvl_index] = data->children_shell_level;
	}
}
