/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 01:42:35 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 22:15:10 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	delete_arg(t_data *data)
{
	t_args_list		*temp;
	t_args_list		*temp2;
	int				i;

	i = 0;
	temp2 = NULL;
	temp = data->args_list;
	while (temp != NULL && i++ != data->curs_po)
	{
		temp2 = temp;
		temp = temp->next;
	}
	if (temp2 != NULL)
		temp2->next = temp->next;
	if (data->args_list == temp)
		data->args_list = temp->next;
	free(temp);
	data->args_nbr--;
	if (data->curs_po == data->args_nbr)
		data->curs_po--;
	set_dynamic_vars(data);
	ft_bzero(data->dyn_sr, 100);
}

void	select_arg(t_data *data)
{
	t_args_list		*temp;
	int				i;

	i = 0;
	temp = data->args_list;
	while (temp != NULL)
	{
		if (i == data->curs_po)
		{
			if (temp->select == 0)
				temp->select = 1;
			else
				temp->select = 0;
			break ;
		}
		temp = temp->next;
		i++;
	}
	down_arrow(data);
	ft_bzero(data->dyn_sr, 100);
}

void	one_col(t_instructions *ins, t_data *data)
{
	int			i;
	t_args_list	*temp;

	i = 0;
	temp = data->args_list;
	while (temp != NULL)
	{
		set_color(temp, data, i);
		if (temp->next != NULL)
		{
			ft_putchar_fd('\n', 0);
			i++;
		}
		temp = temp->next;
	}
	tputs(ins->restor_cursor, 1, reception);
	i = 0;
	while (i++ < data->curs_po)
		tputs(ins->curs_down, 0, reception);
}

void	print_list(t_instructions *ins, t_data *data)
{
	tputs(ins->restor_cursor, 0, reception);
	tputs(ins->clear_down, data->avail_lines - data->initiale_cur_po,
	reception);
	if (data->args_nbr == 0)
		return ;
	if (data->wait == 1)
		return ;
	if (data->one_col == 1)
	{
		one_col(ins, data);
		return ;
	}
	else if (data->breakout_col == 0)
	{
		multi_col_nobrout(ins, data);
		return ;
	}
	else
		breakout_print(ins, data);
}
