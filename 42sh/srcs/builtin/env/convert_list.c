/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:42:37 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 05:27:10 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"

static void				fill_new_env(
							t_local_variables *temp,
							char ***new_env,
							t_local_variables *env_list)
{
	int					i;
	int					string_size;
	char				*temp_buf;

	i = 0;
	while (temp != NULL)
	{
		string_size = ft_strlen(temp->variable_name) + 2;
		if (temp->variable_value != NULL)
			string_size += ft_strlen(temp->variable_value);
		temp_buf = ft_strnew(string_size);
		ft_strcat(temp_buf, temp->variable_name);
		free(temp->variable_name);
		ft_strcat(temp_buf, "=");
		if (temp->variable_value != NULL)
		{
			ft_strcat(temp_buf, temp->variable_value);
			free(temp->variable_value);
		}
		env_list = temp;
		temp = temp->next;
		free(env_list);
		new_env[0][i] = temp_buf;
		i++;
	}
}

void					convert_list_to_ptr_on_string(
								t_local_variables *env_list,
								char ***new_env)
{
	t_local_variables	*temp;
	int					i;

	temp = env_list;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		++i;
	}
	temp = env_list;
	if (!(new_env[0] = (char **)malloc(sizeof(char *) * (i + 1))))
		exit(-1);
	fill_new_env(temp, new_env, env_list);
	new_env[0][i] = NULL;
}
