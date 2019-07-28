/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prerequisites.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:49:00 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 01:22:51 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREREQUISITES_H
# define PREREQUISITES_H

void			create_hash_tab(t_data *data);
void			export_and_adapt_env(t_data *data, char **env);
void			parsing_functions_tab_initialization(t_data *data);
void			set_data_values(t_data *data);
void			set_screen_size(t_data *data);
void			signals_configuration(t_data *data);
t_termcaps		*termcaps_initialization(void);
int				terminal_configuration_management(t_data *data);

#endif
