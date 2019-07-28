/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screensize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 00:57:55 by aanger            #+#    #+#             */
/*   Updated: 2018/11/09 19:58:00 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/ioctl.h>
#include "data_struct.h"

void		set_screen_size(t_data *data)
{
	struct winsize	ws;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		exit(-1);
	data->screen_width = ws.ws_col;
	data->line_nbr = ws.ws_row;
}
