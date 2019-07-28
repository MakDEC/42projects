/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:32:32 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 20:46:56 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_struct.h"
#include "parse_buffer.h"
#include "shell.h"

int					check_local_variables(t_parse_vars *vars)
{
	t_local_variables	*templ;

	templ = vars->data->local_variables;
	while (templ != NULL)
	{
		if (ft_strcmp(vars->temp, templ->variable_name) == 0)
		{
			ft_strcpy(vars->temp, templ->variable_value);
			vars->j = ft_strlen(vars->temp);
			return (0);
		}
		templ = templ->next;
	}
	return (1);
}

static int			dollar_parsing_concat_last_command_status(
					t_parse_vars *vars)
{
	char			*buffer;

	ft_bzero(vars->temp, ft_strlen(vars->temp));
	buffer = ft_itoa(vars->data->last_cmd_status % 255);
	vars->j = ft_strlen(buffer);
	ft_strcat(vars->temp, buffer);
	free(buffer);
	concat_param(vars);
	vars->i++;
	return (0);
}

static void			dollar_parsing_get_variable_name(
						t_parse_vars *vars, char **buf)
{
	while (buf[0][vars->i] && (ft_isalnum(buf[0][vars->i]) == 1
			|| buf[0][vars->i] == '_'))
		vars->temp[vars->j++] = buf[0][vars->i++];
}

int					dollar_parsing(t_data *data,
						t_parse_vars *vars, char **buf)
{
	(void)data;
	vars->i++;
	if (buf[0][vars->i] == '?')
		return (dollar_parsing_concat_last_command_status(vars));
	concat_param(vars);
	dollar_parsing_get_variable_name(vars, buf);
	if (vars->j > 0)
		if (check_local_variables(vars) == 1)
			check_from_env(vars);
	concat_param(vars);
	return (0);
}
