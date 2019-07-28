/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:47:01 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 20:47:15 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"

int		backslash_parsing(t_data *data, t_parse_vars *vars, char **buf)
{
	(void)data;
	vars->temp[vars->j++] = buf[0][++vars->i];
	if (buf[0][vars->i] != 0 && buf[0][vars->i + 1] != 0)
		vars->i++;
	return (0);
}
