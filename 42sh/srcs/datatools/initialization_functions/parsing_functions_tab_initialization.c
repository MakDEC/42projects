/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions_tab_initialization.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:03:19 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 20:03:22 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_buffer.h"
#include <stddef.h>

void		parsing_functions_tab_initialization(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 96)
		data->parsing_functions[i] = NULL;
	data->parsing_functions[(int)('~' - 32)] = tild;
	data->parsing_functions[(int)('<' - 32)] = left_rafter;
	data->parsing_functions[(int)('>' - 32)] = right_rafter;
	data->parsing_functions[(int)('\'' - 32)] = squote;
	data->parsing_functions[(int)('"' - 32)] = dquote;
	data->parsing_functions[(int)('|' - 32)] = pipe_parsing;
	data->parsing_functions[(int)('&' - 32)] = esp_parsing;
	data->parsing_functions[(int)(' ' - 32)] = space_parsing;
	data->parsing_functions[(int)('\\' - 32)] = backslash_parsing;
	data->parsing_functions[(int)('$' - 32)] = dollar_parsing;
	data->parsing_functions[(int)(';' - 32)] = semicolon;
}
