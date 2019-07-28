/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input_redirections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:36:05 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:16 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "monitor.h"
#include "sigint.h"
#include <signal.h>

static int				open_redirected_file(t_redirection *temp)
{
	if ((temp->redirection_fd = open(temp->redirection,
					O_RDONLY)) == -1)
	{
		ft_putstr_fd("42sh: no such file or directory:  ", 2);
		ft_putendl_fd(temp->redirection, 2);
		return (1);
	}
	return (0);
}

int						prepare_input_redirections(t_redirection *red_case)
{
	t_redirection	*temp;

	temp = red_case;
	if (temp->double_rafter == 0)
	{
		if (temp->redirection != NULL)
		{
			if (open_redirected_file(temp) != 0)
				return (1);
		}
	}
	return (0);
}
