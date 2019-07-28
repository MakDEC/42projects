/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:58:27 by aanger            #+#    #+#             */
/*   Updated: 2019/04/23 19:36:01 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include <stdlib.h>
#include <unistd.h>

void			clear_redirections(
				t_params_list *node)
{
	t_redirection	*temp;

	while (node->redirections != NULL)
	{
		if (node->redirections->redirection != NULL)
		{
			free(node->redirections->redirection);
			if (node->redirections->redirection_fd != -1)
				close(node->redirections->redirection_fd);
		}
		temp = node->redirections;
		node->redirections = node->redirections->next;
		free(temp);
	}
	node->redirections = NULL;
}
