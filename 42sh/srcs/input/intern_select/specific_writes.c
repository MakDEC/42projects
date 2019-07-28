/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_writes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:16:16 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:11 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_struct.h"
#include "libft.h"

void			write_normal_char_keep_cursor_unchanged(
		t_select_data *select_data)
{
	char		write_buffer[6];

	ft_bzero(write_buffer, 6);
	write_buffer[0] = select_data->current_buffer->
		buffer[select_data->cur_buf_i];
	ft_strcat(write_buffer, "\033[1D");
	write(1, write_buffer, 5);
}

void			write_reverse_char(t_select_data *select_data,
		int stay_on)
{
	char		write_buffer[20];

	ft_bzero(write_buffer, 20);
	ft_strcat(write_buffer, "\033[7;m");
	write_buffer[5] = select_data->current_buffer->buffer
		[select_data->cur_buf_i];
	if (stay_on == 1)
		ft_strcat(write_buffer, "\033[1D");
	ft_strcat(write_buffer, "\033[0m");
	write(1, write_buffer, ft_strlen(write_buffer));
}
