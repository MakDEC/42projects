/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:56:09 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 04:04:47 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "data_struct.h"

int		cd_builtin(t_data *data,
			t_params_list *params_list);

int		echo_builtin(
			t_params_list *params_list);

int		exit_builtin(t_data *data,
			t_params_list *params_list);

int		fg_builtin(t_data *data, t_params_list *params_list);

int		jobs(t_data *data);

int		local_variables_builtin(t_data *data,
			t_params_list *params_list);

/*
**			Environment Functions Builtins
*/

int		env_input(t_data *data,
			t_params_list *params_list);

void	existing_var(t_local_variables *vars, char *var, char *value,
				t_params_list *params_list);
int		ft_setenv(t_data *data,
			t_params_list *params_list);
int		ft_env(t_data *data,
			t_params_list *params_list);
int		ft_unsetenv(t_data *data,
			t_params_list *params_list);

#endif
