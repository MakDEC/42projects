/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirected_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 23:59:45 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:17 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_struct.h"
#include "parse_buffer.h"
#include "libft.h"

int			set_redirected_fd(char **buf, t_parse_vars *vars,
		t_redirection *temp)
{
	if (vars->i == 0 || buf[0][vars->i - 1] == ' ')
	{
		temp->redirected_fd = 1;
		return (0);
	}
	if (vars->i > 0 && buf[0][vars->i - 1] != ' ')
		if (buf[0][vars->i - 1] < 48 || buf[0][vars->i - 1] > 57
				|| (vars->i > 1 && buf[0][vars->i - 2] != ' '))
		{
			temp->redirected_fd = 1;
			concat_param(vars);
			return (0);
		}
	vars->temp[--vars->j] = 0;
	temp->redirected_fd = buf[0][vars->i - 1] - 48;
	return (0);
}
