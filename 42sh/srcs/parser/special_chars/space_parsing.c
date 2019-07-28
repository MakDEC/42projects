/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:16:56 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 20:17:03 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "data_struct.h"
#include "parse_buffer.h"

int				space_parsing(t_data *data, t_parse_vars *vars, char **buf)
{
	(void)data;
	concat_param(vars);
	while (buf[0][vars->i] == ' ' || buf[0][vars->i] == '\t')
		vars->i++;
	if (buf[0][vars->i] != 0 && vars->params->buf != NULL)
		new_param(vars->params);
	return (0);
}
