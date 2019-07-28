/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct_initialization.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:20:35 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 22:54:53 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include <stdlib.h>
#include "prerequisites.h"

t_data		*init_data_struct(char **env)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		exit(-1);
	data->termcaps = termcaps_initialization();
	terminal_configuration_management(data);
	set_screen_size(data);
	set_data_values(data);
	export_and_adapt_env(data, env);
	create_hash_tab(data);
	parsing_functions_tab_initialization(data);
	signals_configuration(data);
	return (data);
}
