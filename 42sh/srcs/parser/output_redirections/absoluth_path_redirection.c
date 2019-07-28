/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absoluth_path_redirection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:33:56 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:17 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse_struct.h"

static int			bad_redirection_destination_error(void)
{
	write(2, "Parsing problem, no redirection destination\n", 44);
	return (1);
}

static int			fill_redirection_buffer(t_redirection *temp, int i,
		t_parse_vars *vars, char **buf)
{
	int				j;

	if (!(temp->redirection = (char*)malloc(sizeof(char) * i)))
		exit(-1);
	ft_bzero(temp->redirection, i);
	j = 0;
	while (--i > 0)
		temp->redirection[j++] = buf[0][vars->i - i];
	return (0);
}

int					absoluth_path_output_redirection(char **buf,
		t_parse_vars *vars, t_redirection *temp)
{
	int				i;

	i = 0;
	while (buf[0][vars->i] && (buf[0][vars->i] == ' '
				|| buf[0][vars->i] == '\t'))
		vars->i++;
	if (buf[0][vars->i] == 0 || buf[0][vars->i] == ';')
		return (bad_redirection_destination_error());
	while (buf[0][vars->i] && buf[0][vars->i] != ' ' && buf[0][vars->i] != '\t'
			&& buf[0][vars->i] != '|' && buf[0][vars->i] != ';'
			&& buf[0][vars->i] != '$' && buf[0][vars->i] != '>'
			&& buf[0][vars->i] != '<')
	{
		vars->i++;
		i++;
	}
	if (i++ == 0)
		return (bad_redirection_destination_error());
	return (fill_redirection_buffer(temp, i, vars, buf));
}
