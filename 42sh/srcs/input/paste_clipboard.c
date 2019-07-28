/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_clipboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:47:45 by aanger            #+#    #+#             */
/*   Updated: 2019/03/22 15:15:46 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "input_struct.h"
#include "reader.h"
#include "libft.h"

void		paste_clipboard(t_data *data, t_reader *read_data)
{
	int			index;

	if (data->clipboard == NULL)
	{
		write(1, "\a", 1);
		return ;
	}
	ft_bzero(read_data->input_buf, 8);
	index = -1;
	while (data->clipboard[++index] != 0)
	{
		read_data->input_buf[0] = data->clipboard[index];
		if (read_data->input_buf[0] != ' ')
			add_inline_character(data, read_data);
		else
			space(data, read_data);
	}
}
