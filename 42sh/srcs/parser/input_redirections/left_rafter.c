/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_rafter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:43:59 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:31:46 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_buffer.h"
#include "libft.h"

static int				write_parsing_error_and_quit(void)
{
	write(2, "Parsing problem for input redirection\n", 38);
	return (1);
}

static int				set_input_redirection_fd(
								char **buf,
								t_parse_vars *vars)
{
	t_redirection		*temp;

	if (buf[0][++vars->i] && (buf[0][vars->i] < 48
				|| buf[0][vars->i] > 57))
	{
		ft_putstr_fd("21sh : bad file descriptor\n", 2);
		return (1);
	}
	temp = set_temp_case(vars);
	if (buf[0][vars->i] && buf[0][vars->i] == '-')
		temp->redirection_fd = -2;
	else
		temp->redirection_fd = buf[0][vars->i] - 48;
	temp->redirected_fd = 0;
	temp->double_rafter = 0;
	return (0);
}

static int				check_double_rafter(
							char **buf,
							t_parse_vars *vars)
{
	if (buf[0][++vars->i] && buf[0][vars->i] == '<')
	{
		vars->i++;
		return (1);
	}
	if (buf[0][vars->i] && buf[0][vars->i] == '>')
		return (-1);
	return (0);
}

int						rafter_check_next_char(
								char **buf,
								t_parse_vars *vars)
{
	while (buf[0][vars->i] == ' ')
		vars->i++;
	if (buf[0][vars->i] == '<' || buf[0][vars->i] == '>'
			|| buf[0][vars->i] == '|' || buf[0][vars->i] == ';')
		return (1);
	return (0);
}

int						left_rafter(
								t_data *data,
								t_parse_vars *vars,
								char **buf)
{
	int					double_rafter;
	int					j;

	(void)data;
	j = 0;
	if ((double_rafter = check_double_rafter(buf, vars)) == -1
			|| rafter_check_next_char(buf, vars) != 0)
		return (write_parsing_error_and_quit());
	if (!buf[0][vars->i] || buf[0][vars->i] == '<')
		return (write_parsing_error_and_quit());
	if (buf[0][vars->i] == '&')
		return (set_input_redirection_fd(buf, vars));
	while (buf[0][vars->i + 1] && buf[0][vars->i + 1] == ' ')
		vars->i++;
	if (buf[0][vars->i] != ' ')
		j++;
	while (buf[0][++vars->i] && buf[0][vars->i] != ' ')
		j++;
	if (j == 0)
		return (write_parsing_error_and_quit());
	if (set_input_redirection_case(buf, j, vars, double_rafter) != 0)
		return (sigint_management(vars));
	return (0);
}
