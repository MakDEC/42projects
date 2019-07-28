/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:00:58 by aanger            #+#    #+#             */
/*   Updated: 2019/04/09 16:42:02 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include "data_struct.h"

void				monitor(t_data *data);
t_data				*init_data_struct(char **env);
void				free_data(t_data *data);

#endif
