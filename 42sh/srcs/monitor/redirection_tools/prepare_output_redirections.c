/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_output_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 02:53:31 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:31:02 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"

static int		convert_path_to_fd(
					t_redirection *node,
					t_params_list *params)
{
	if (node->double_rafter == 0)
	{
		if ((node->redirection_fd = open(node->redirection, O_WRONLY
						| O_CREAT | O_TRUNC | O_NONBLOCK, 0644)) == -1)
		{
			ft_putstr_fd("21sh: no such file or directory: ", params->fd[2]);
			ft_putendl_fd(node->redirection, params->fd[2]);
			return (1);
		}
	}
	else if ((node->redirection_fd = open(node->redirection, O_WRONLY
					| O_CREAT | O_APPEND | O_NONBLOCK, 0644)) == -1)
	{
		ft_putstr_fd("21sh: no such file or directory: ", params->fd[2]);
		ft_putendl_fd(node->redirection, params->fd[2]);
		return (1);
	}
	return (0);
}

static int		check_file_disponibility(
					char *file_name,
					t_params_list *node)
{
	struct stat			filestat;

	if (stat(file_name, &filestat) == -1)
		return (0);
	if (S_ISDIR(filestat.st_mode) == 1)
	{
		ft_putstr_fd("42sh: is a directory: ", node->fd[2]);
		ft_putendl_fd(file_name, node->fd[2]);
		return (1);
	}
	if (access(file_name, W_OK) != 0)
	{
		ft_putstr_fd("42sh: permission denied: ", node->fd[2]);
		ft_putendl_fd(file_name, node->fd[2]);
		return (1);
	}
	return (0);
}

int				prepare_output_redirections(
					t_params_list *node,
					t_redirection *temp)
{
	if (temp->redirection != NULL)
	{
		if (check_file_disponibility(temp->redirection, node) != 0
				|| convert_path_to_fd(temp, node) != 0)
			return (1);
	}
	if (temp->redirected_fd >= 0 && temp->redirected_fd <= 2
			&& temp->redirection_fd != node->fd[temp->redirected_fd])
	{
		if (temp->redirection_fd >= 0 && temp->redirection_fd <= 2)
			node->fd[temp->redirected_fd] = node->fd[temp->redirection_fd];
		else
			node->fd[temp->redirected_fd] = temp->redirection_fd;
	}
	return (0);
}
