/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 03:40:38 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:29:57 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "monitor.h"
#include "libft.h"

static int	set_output_redirection(
				t_redirection *node)
{
	if (node->redirection_fd == -2)
	{
		close(node->redirected_fd);
		return (0);
	}
	if (dup2(node->redirection_fd, node->redirected_fd) == -1)
		close(node->redirected_fd);
	return (0);
}

int			apply_redirections(
				t_params_list *params_list)
{
	t_redirection	*temp;

	temp = params_list->redirections;
	while (temp != NULL)
	{
		if (temp->input_redirection == 0)
			set_output_redirection(temp);
		else if (dup2(temp->redirection_fd, temp->redirected_fd) == -1)
			close(temp->redirected_fd);
		temp = temp->next;
	}
	return (0);
}
