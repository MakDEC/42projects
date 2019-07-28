/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_rafter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 23:49:56 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:36:29 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_buffer.h"
#include "parse_struct.h"
#include "libft.h"

static int				convert_to_int(
								char **buf,
								t_parse_vars *vars,
								int i)
{
	char				*temp_buf;
	int					j;
	int					ret_value;

	j = 0;
	i++;
	if (!(temp_buf = (char*)malloc(sizeof(char) * i)))
		exit(-1);
	ft_bzero(temp_buf, i);
	while (--i > 0)
		temp_buf[j++] = buf[0][vars->i - i];
	ret_value = ft_atoi(temp_buf);
	free(temp_buf);
	return (ret_value);
}

static int				right_rafter_parsing_error(void)
{
	ft_putstr_fd("42sh: Parsing error for redirection\n", 2);
	return (1);
}

static int				set_output_redirection_destination(
								char **buf,
								t_parse_vars *vars,
								t_redirection *temp)
{
	int					i;

	if (buf[0][vars->i] != '&')
		return (absoluth_path_output_redirection(buf, vars, temp));
	while (buf[0][vars->i] && buf[0][vars->i] == ' ')
		vars->i++;
	if (buf[0][vars->i + 1] == 0 || buf[0][vars->i + 1] == ';')
		return (right_rafter_parsing_error());
	vars->i++;
	if (buf[0][vars->i] && buf[0][vars->i] == '-')
	{
		temp->redirection_fd = -2;
		vars->i++;
		return (0);
	}
	if (buf[0][vars->i] < 48 || buf[0][vars->i] > 57)
		return (right_rafter_parsing_error());
	i = 0;
	while (buf[0][vars->i] && buf[0][vars->i] >= 48 && buf[0][vars->i] <= 57)
	{
		vars->i++;
		i++;
	}
	temp->redirection_fd = convert_to_int(buf, vars, i);
	return (0);
}

static t_redirection	*set_new_redirect_case(
								t_parse_vars *vars)
{
	t_redirection		*temp;

	temp = vars->redirections;
	if (temp == NULL)
	{
		vars->redirections = create_redirection_case();
		temp = vars->redirections;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = create_redirection_case();
		temp = temp->next;
	}
	temp->input_redirection = 0;
	return (temp);
}

int						right_rafter(
								t_data *data,
								t_parse_vars *vars,
								char **buf)
{
	t_redirection		*temp;

	(void)data;
	temp = set_new_redirect_case(vars);
	set_redirected_fd(buf, vars, temp);
	if (buf[0][++vars->i] == '>')
	{
		temp->double_rafter = 1;
		vars->i++;
	}
	if (buf[0][vars->i] == '|')
	{
		ft_putstr_fd(">| syntax not managed\n", 2);
		return (1);
	}
	if (set_output_redirection_destination(buf, vars, temp) != 0)
		return (1);
	return (0);
}
