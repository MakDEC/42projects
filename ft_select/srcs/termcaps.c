/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testrmcaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 23:57:44 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 21:41:33 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		reception(int c)
{
	ft_putchar_fd((char)c, 0);
	return (0);
}

void	free_data(t_data *data)
{
	t_args_list		*temp;

	while (data->args_list != NULL)
	{
		temp = data->args_list;
		data->args_list = data->args_list->next;
		free(temp);
	}
	free(data);
}

int		main(int argc, char **argv)
{
	t_data			*data;
	t_instructions	*ins;
	int				ret_read_loop;
	struct termios	original_term;

	if (argc < 2)
		return (0);
	if (tcgetattr(0, &original_term) != 0)
		exit(-1);
	prep_term();
	init_sig();
	ins = init_ins();
	data = init_data(argc, argv, original_term);
	ret_read_loop = read_loop(ins, data);
	tputs(ins->restor_cursor, 0, reception);
	tputs(ins->clear_down, 0, reception);
	free(ins);
	if (ret_read_loop == 1)
		finish(data);
	tcsetattr(0, 0, &original_term);
	free_data(data);
	return (0);
}
