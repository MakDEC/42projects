/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:34:35 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 04:13:14 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include "data_struct.h"
# include <stddef.h>

typedef struct	s_cd_variables
{
	char		*directory;
	int			mode;
	int			directory_position;
}				t_cd_variables;

int				cd_check_special_params(t_data *data, t_cd_variables *cd_vars,
						t_params_list *params_list);

void			cd_option_error(t_params_list *params_list, char wrong_option);

void			fill_directory(char **parsed_path, int index, char **directory,
						size_t size_to_malloc);

char			*prepare_directory_from_absoluth_path(t_cd_variables *cd_vars,
						t_params_list *params_list);

char			*prepare_directory_from_relative_path(t_data *data,
						t_cd_variables *cd_variables,
						t_params_list *params_list);

char			**prepare_parsed_path(t_data *data, t_cd_variables *cd_vars,
						t_params_list *params_list);

#endif
