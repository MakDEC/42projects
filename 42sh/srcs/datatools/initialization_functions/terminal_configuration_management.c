/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_configuration_management.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:01:58 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 20:02:06 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include <stdlib.h>
#include <termios.h>

int		terminal_configuration_management(t_data *data)
{
	if (tcgetattr(0, &data->original_term_config) != 0)
		exit(-1);
	if (tcgetattr(0, &data->intern_term_config) != 0)
		exit(-1);
	data->intern_term_config.c_lflag &= ~(ICANON | ECHO);
	data->intern_term_config.c_lflag &= (ISIG);
	tcsetattr(0, 0, &data->intern_term_config);
	return (0);
}
