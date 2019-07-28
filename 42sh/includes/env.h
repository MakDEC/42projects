/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 23:28:31 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 04:13:38 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "data_struct.h"
# include "cd.h"

typedef struct			s_env_variables
{
	char				**new_env;
	int					param_index;
	int					option_i;
}						t_env_variables;

void					change_env_variables(t_data *data, char *newwd,
								char *oldwd, t_params_list *params_list);
int						check_env(char **env, char *var);
int						check_env_params(t_data *data,
								t_env_variables *env_variables,
								t_params_list *params_list);
void					convert_list_to_ptr_on_string(
								t_local_variables *env_list,
								char ***new_env);
t_local_variables		*export_env_to_list(t_data *data,
								t_local_variables *env_list);
void					free_hash_tab(t_hash_tab *temp);
int						prepare_new_env(t_data *data,
								t_env_variables *env_vars,
								t_params_list *params_list);
void					remove_hash_table(t_data *data);
void					split_variable(t_data *data, t_local_variables *temp,
								int env_index);
void					print_env(t_data *data, t_params_list *params_list);

#endif
