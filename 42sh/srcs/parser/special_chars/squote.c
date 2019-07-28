/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:12:49 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 15:50:54 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "sigint.h"
#include "parse_buffer.h"
#include "monitor.h"
#include <signal.h>

static int	search_quote(char **buf, t_parse_vars *vars)
{
	while (buf[0][++vars->i] != 0 && buf[0][vars->i] != '\'')
	{
		vars->temp[vars->j++] = buf[0][vars->i];
		if (vars->j == 4095)
			concat_param(vars);
	}
	if (vars->j > 0)
		concat_param(vars);
	if (buf[0][vars->i] == '\'')
	{
		vars->i++;
		return (1);
	}
	return (0);
}

static void	squote_control_d_error(void)
{
	ft_putstr_fd("42sh: unexpected EOF while looking", 2);
	ft_putstr_fd(" for matching simple quote\n", 2);
	ft_putstr_fd("42sh: syntax error: unexpected end of file\n", 2);
}

static int	squote_routine(t_data *data, char **buf, t_parse_vars *vars)
{
	int			ret;

	ret = 0;
	while (ret != 1)
	{
		free(buf[0]);
		buf[0] = NULL;
		ft_putstr("quote> ");
		ret = reader(data, buf);
		if (data->exit_status != -1)
		{
			squote_control_d_error();
			data->exit_status = -1;
		}
		if (ret != 0)
			return (ret);
		vars->i = -1;
		vars->j = 0;
		vars->temp[vars->j++] = '\n';
		ret = search_quote(buf, vars);
	}
	vars->j = 0;
	return (0);
}

int			squote(t_data *data, t_parse_vars *vars, char **buf)
{
	concat_param(vars);
	search_quote(buf, vars);
	if (buf[0][vars->i] != '\'')
		return (squote_routine(data, buf, vars));
	vars->i++;
	return (0);
}
