/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:49:26 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 21:20:56 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"

int				echo_builtin(t_params_list *params_list)
{
	int		i;

	i = 1;
	if (params_list->fd[2] < 0)
		return (0);
	while (params_list->params[i] != NULL)
	{
		if (i > 1)
			ft_putchar_fd(' ', params_list->fd[1]);
		ft_putstr_fd(params_list->params[i], params_list->fd[1]);
		i++;
	}
	ft_putchar_fd('\n', params_list->fd[1]);
	return (0);
}
