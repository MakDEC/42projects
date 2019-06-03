/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 02:05:50 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 19:02:51 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>

t_data			*g_data;
t_instructions	*g_ins;

int			read_buffer(char buffer[5], t_data *data, int ret_read)
{
	if (ret_read == 3 && buffer[0] == 27)
		arrow(data, buffer);
	else if (ret_read == 1 && buffer[0] == 32)
		select_arg(data);
	else if (ret_read == 1 && (buffer[0] == 126 || buffer[0] == 127))
		delete_arg(data);
	else if (ret_read == 1 && buffer[0] == 27)
		return (2);
	else if (ret_read == 1 && buffer[0] == 10)
		return (1);
	else if (ret_read == 1 && ft_isprint(buffer[0]) == 1)
		dyn_buf(data, buffer[0]);
	return (0);
}

int			read_loop(t_instructions *ins, t_data *data)
{
	char	buffer[5];
	int		ret_read;
	int		ret_read_buf;

	prep_term();
	g_data = data;
	g_ins = ins;
	ft_bzero(buffer, 5);
	print_list(ins, data);
	ret_read_buf = 0;
	while (1)
	{
		if (data->args_nbr == 0)
			return (0);
		ret_read = read(0, buffer, 3);
		if (ret_read >= 0)
			buffer[ret_read] = 0;
		ret_read_buf = read_buffer(buffer, data, ret_read);
		if (ret_read_buf != 0)
			return (ret_read_buf);
		print_list(ins, data);
	}
	return (0);
}
