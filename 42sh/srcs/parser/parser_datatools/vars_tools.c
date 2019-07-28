/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:28:51 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:18 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_struct.h"
#include "libft.h"

void				new_param(t_params *params)
{
	if (!(params->next = (t_params*)malloc(sizeof(t_params))))
		exit(-1);
	params = params->next;
	params->buf = NULL;
	params->next = NULL;
}

static void			intern_realloc_buffer(t_parse_vars *vars)
{
	char		*tempo;

	tempo = ft_strdup(vars->params->buf);
	free(vars->params->buf);
	vars->params->buf = ft_strnew(ft_strlen(tempo) +
			ft_strlen(vars->temp) + 1);
	ft_bzero(vars->params->buf, ft_strlen(tempo) +
			ft_strlen(vars->temp) + 1);
	ft_strcat(vars->params->buf, tempo);
	free(tempo);
}

void				concat_param(t_parse_vars *vars)
{
	if (vars->j == 0)
		return ;
	if (vars->params->buf == NULL)
		vars->params->buf = ft_strnew(ft_strlen(vars->temp));
	else
		intern_realloc_buffer(vars);
	ft_strcat(vars->params->buf, vars->temp);
	ft_bzero(vars->temp, vars->j);
	vars->j = 0;
}
