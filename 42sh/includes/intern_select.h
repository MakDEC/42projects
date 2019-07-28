/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_select.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:14:17 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 01:15:58 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_SELECT_H
# define INTERN_SELECT_H

# include "data_struct.h"
# include "input_struct.h"

void			select_left_arrow(t_data *data, t_select_data *select_data);
void			select_right_arrow(t_data *data, t_select_data *select_data);
int				reception(int c);
void			write_reverse_char(t_select_data *select_data,
						int stay_on);
void			write_normal_char_keep_cursor_unchanged(
						t_select_data *select_data);
t_select_data	*prepare_select_struct(t_data *data,
						t_reader *read_data);
int				reception(int c);
void			save_and_free_select_data(t_data *data,
						t_select_data *select_data);
void			free_select_data(t_select_data *select_data);

#endif
