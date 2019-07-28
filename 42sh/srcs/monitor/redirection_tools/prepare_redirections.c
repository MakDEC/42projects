/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:30:05 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:30:25 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stddef.h>

static int		prepare_redirections(
					t_params_list *node)
{
	t_redirection	*temp;

	node->fd[0] = 0;
	node->fd[1] = 1;
	node->fd[2] = 2;
	temp = node->redirections;
	while (temp != NULL)
	{
		if (temp->input_redirection == 1)
		{
			if (prepare_input_redirections(temp) != 0)
				return (1);
		}
		else if (prepare_output_redirections(node, temp) != 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int				prepare_all_redirections(
					t_params_list *params_list)
{
	while (params_list != NULL)
	{
		if (prepare_redirections(params_list) != 0)
			return (1);
		params_list = params_list->next;
	}
	return (0);
}
