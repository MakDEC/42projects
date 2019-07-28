/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 03:47:48 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 03:55:20 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdlib.h>

t_local_variables			*export_env_to_list(
									t_data *data,
									t_local_variables *env_list)
{
	int						env_index;
	t_local_variables		*temp;

	env_index = 0;
	if (!(env_list = (t_local_variables *)malloc(sizeof(t_local_variables))))
		exit(-1);
	temp = env_list;
	split_variable(data, temp, env_index);
	temp->next = NULL;
	while (data->env[++env_index] != NULL)
	{
		if (!(temp->next = (t_local_variables *)
						malloc(sizeof(t_local_variables))))
			exit(-1);
		temp = temp->next;
		split_variable(data, temp, env_index);
		temp->next = NULL;
	}
	return (env_list);
}
