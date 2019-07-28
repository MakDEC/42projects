/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_wrong_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:45:21 by aanger            #+#    #+#             */
/*   Updated: 2019/04/04 23:08:08 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"

void			cd_option_error(t_params_list *params_list, char wrong_option)
{
	ft_putstr_fd("42sh: cd: -", params_list->fd[2]);
	ft_putchar_fd(wrong_option, params_list->fd[2]);
	ft_putstr_fd(": invalid option\n", params_list->fd[2]);
	ft_putstr_fd("cd: usage: cd [-L|-P] [dir]\n", params_list->fd[2]);
}
