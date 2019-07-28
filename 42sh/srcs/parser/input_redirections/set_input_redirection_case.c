/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input_redirection_case.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:19:42 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 14:23:00 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"
#include "parse_buffer.h"

t_redirection			*set_temp_case(t_parse_vars *vars)
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
	return (temp);
}

int						set_input_redirection_case(char **buf, int j,
		t_parse_vars *vars, int double_rafter)
{
	t_redirection		*temp;

	temp = set_temp_case(vars);
	temp->input_redirection = 1;
	if (!(temp->redirection = (char*)malloc(sizeof(char) * (j + 1))))
		exit(-1);
	ft_bzero(temp->redirection, (j + 1));
	ft_strncpy(temp->redirection, &buf[0][vars->i - j], j);
	temp->double_rafter = double_rafter;
	temp->redirected_fd = 0;
	if (double_rafter == 1)
	{
		if ((temp->redirection_fd = prepare_heredoc(vars->data,
						temp->redirection, buf, vars)) == -1)
			return (1);
	}
	return (0);
}
