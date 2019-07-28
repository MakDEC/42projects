/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalid_com.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:07:47 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 21:26:49 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"

int			ft_invalid_com(
				t_params_list *params_list,
				char *buf)
{
	ft_putstr_fd("42sh: command not found: ", params_list->fd[2]);
	ft_putendl_fd(buf, params_list->fd[2]);
	return (-1);
}
