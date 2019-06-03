/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 20:36:14 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 16:42:45 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	write_type(t_args_list *temp, t_data *data, int arg_curs_on)
{
	if (temp->select == 1 && data->curs_po == arg_curs_on)
		write_underinv(temp->arg);
	else if (temp->select == 1)
		write_inverse(temp->arg);
	else if (data->curs_po == arg_curs_on)
		write_underline(temp->arg);
	else
		ft_putstr_fd(temp->arg, 0);
}

void		set_color(t_args_list *temp, t_data *data, int arg_curs_on)
{
	if (ft_strcmp(&temp->arg[ft_strlen(temp->arg) - 4], ".txt") == 0)
		write(0, "\033[34m", 5);
	else if (ft_strcmp(&temp->arg[ft_strlen(temp->arg) - 2], ".c") == 0)
		write(0, "\033[36m", 5);
	else if (ft_strcmp(&temp->arg[ft_strlen(temp->arg) - 2], ".h") == 0)
		write(0, "\033[37m", 5);
	else if (ft_strcmp(&temp->arg[ft_strlen(temp->arg) - 3], ".sh") == 0)
		write(0, "\033[33m", 5);
	write_type(temp, data, arg_curs_on);
	write(0, "\033[0m", 4);
}
