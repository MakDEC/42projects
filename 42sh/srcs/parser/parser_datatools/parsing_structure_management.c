/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:33:55 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:40:42 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "parse_struct.h"
#include "parse_buffer.h"
#include "libft.h"

/*
**		This function create a new list of buffers in the parsing structure
**		We malloc the first case, set pointers and erase our temp buffer
**		The list is free when buffers are export to data
**		(at the end or when we met an operator : & , | , ;
*/

void				new_buffers_list_in_parsing_struct(
					t_parse_vars *vars)
{
	if (!(vars->begin = (t_params*)malloc(sizeof(t_params))))
		exit(-1);
	vars->params = vars->begin;
	vars->params->buf = NULL;
	vars->params->next = NULL;
	vars->redirections = NULL;
	ft_bzero(vars->temp, 4096);
	vars->j = 0;
}

/*
**		The parsing variables pointer will be free at the end of the parsing
*/

t_parse_vars		*prepare_parsing_structure_variables(
				t_parse_vars *vars, t_data *data)
{
	if (!(vars = (t_parse_vars*)malloc(sizeof(t_parse_vars))))
		exit(-1);
	new_buffers_list_in_parsing_struct(vars);
	vars->data = data;
	create_full_job_architecture(data, vars);
	vars->i = 0;
	return (vars);
}
