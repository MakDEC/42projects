/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_to_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:18:54 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:37:10 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "parse_struct.h"
#include "parse_buffer.h"

static	int			number_of_parameters_to_malloc(t_params *begin)
{
	int			i;

	i = 0;
	while (begin != NULL)
	{
		i++;
		begin = begin->next;
	}
	return (i + 1);
}

void				export_command_to_logical_tree(
					t_data *data,
					t_params *begin,
					t_parse_vars *vars)
{
	int			i;
	t_params	*temp;

	(void)data;
	temp = begin;
	if (!(vars->params_list_case->params = (char **)malloc(sizeof(char *)
					* number_of_parameters_to_malloc(begin))))
		exit(-1);
	i = 0;
	while (temp != NULL)
	{
		vars->params_list_case->params[i++] = temp->buf;
		temp->buf = NULL;
		begin = temp;
		temp = temp->next;
		free(begin);
		begin = NULL;
	}
	vars->params_list_case->params[i] = NULL;
	vars->params_list_case->argc = i;
	vars->params_list_case->redirections = vars->redirections;
	free(temp);
}
