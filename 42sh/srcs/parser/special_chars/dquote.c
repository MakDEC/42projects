/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dquote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:12:49 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 04:50:48 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse_buffer.h"
#include "sigint.h"
#include "monitor.h"
#include <signal.h>

static void		dquote_expansions_management(
						t_data *data,
						char **buf,
						t_parse_vars *vars)
{
	if (vars->j > 0)
		concat_param(vars);
	if (buf[0][vars->i] == '~')
		tild(data, vars, buf);
	else
	{
		dollar_parsing(data, vars, buf);
		vars->i--;
	}
}

int				search_dquote(
						t_data *data,
						char **buf,
						t_parse_vars *vars)
{
	while (buf[0][++vars->i] != 0 && buf[0][vars->i] != '"')
	{
		if (buf[0][vars->i] == '\\')
			vars->temp[vars->j++] = buf[0][++vars->i];
		else if (buf[0][vars->i] == '$' || buf[0][vars->i] == '~')
			dquote_expansions_management(data, buf, vars);
		else
			vars->temp[vars->j++] = buf[0][vars->i];
		if (vars->j == 998)
			concat_param(vars);
	}
	if (vars->j > 0)
		concat_param(vars);
	if (buf[0][vars->i] == '"')
		return (1);
	return (0);
}

static void		dquote_control_d_error(void)
{
	ft_putstr_fd("42sh: unexpected EOF while looking ", 2);
	ft_putstr_fd("for matching double quote\n", 2);
	ft_putstr_fd("42sh: syntax error: unexpected end of file\n", 2);
}

static int		dquote_routine(
						t_data *data,
						char **buf,
						t_parse_vars *vars)
{
	int		ret;

	ret = 0;
	while (ret != 1)
	{
		free(buf[0]);
		buf[0] = NULL;
		ft_putstr("dquote> ");
		ret = reader(data, buf);
		if (data->exit_status != -1)
		{
			dquote_control_d_error();
			data->exit_status = -1;
			return (-1);
		}
		if (ret != 0)
			return (ret);
		vars->i = -1;
		vars->j = 0;
		vars->temp[vars->j++] = '\n';
		ret = search_dquote(data, buf, vars);
	}
	return (0);
}

int				dquote(
						t_data *data,
						t_parse_vars *vars,
						char **buf)
{
	concat_param(vars);
	if (search_dquote(data, buf, vars) == 0)
		dquote_routine(data, buf, vars);
	if (buf[0] == NULL)
		ft_putstr("WARNING\n");
	vars->i++;
	vars->j = 0;
	return (0);
}
