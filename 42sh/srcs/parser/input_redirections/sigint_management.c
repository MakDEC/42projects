/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 00:29:26 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 01:19:55 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parse_buffer.h"

static void				free_parsed_params_after_stop_heredoc(t_params *begin)
{
	t_params	*temp;

	if (begin == NULL)
		return ;
	if (begin->buf != NULL)
		free(begin->buf);
	temp = begin->next;
	while (temp != NULL && temp->buf != NULL)
	{
		ft_bzero(temp->buf, ft_strlen(temp->buf));
		free(temp->buf);
		begin = temp;
		temp = temp->next;
		free(begin);
	}
	if (temp != NULL)
		free(temp);
	begin->next = NULL;
}

int						sigint_management(t_parse_vars *vars)
{
	free_parsed_params_after_stop_heredoc(vars->begin);
	vars->params = vars->begin;
	vars->i = -1;
	vars->j = 0;
	return (0);
}
