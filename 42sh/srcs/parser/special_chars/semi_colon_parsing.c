/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semi_colon_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:19:14 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 20:19:22 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "parse_buffer.h"
#include <stdlib.h>

int			semicolon(t_data *data, t_parse_vars *vars, char **buf)
{
	(void)buf;
	concat_param(vars);
	export_command_to_logical_tree(data, vars->begin, vars);
	job_loader(data);
	create_full_job_architecture(data, vars);
	if (!(vars->begin = (t_params*)malloc(sizeof(t_params))))
		exit(-1);
	vars->params = vars->begin;
	vars->params->buf = NULL;
	vars->params->next = NULL;
	vars->redirections = NULL;
	vars->i++;
	return (0);
}
