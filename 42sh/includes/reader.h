/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 04:23:25 by aanger            #+#    #+#             */
/*   Updated: 2019/05/05 20:40:43 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include "data_struct.h"
# include "input_struct.h"

void			arrow(t_data *data, t_reader *read_data);
void			ring_bell(void);
int				line_width(t_data *data, t_reader *read_data);
t_reader		*init_reader_data(t_data *data);
t_bufstock		*new_buffers_node(t_bufstock *previous, t_bufstock *next,
				int line, int is_com);
int				reception(int c);
void			space(t_data *data, t_reader *read_data);
void			add_inline_character(t_data *data, t_reader *read_data);
int				backspace(t_data *data, t_reader *read_data);
void			back_to_begin(t_data *data, t_reader *read_data);
void			left_arrow(t_data *data, t_reader *read_data);
void			reprint_input(t_data *data, t_reader *read_data);
void			cursor_to_end(t_data *data, t_reader *read_data);
void			stock_history(t_data *data, t_reader *read_data);
void			free_bufstock(t_bufstock *buffers);
void			move_line_up(t_data *data, t_reader *read_data);
void			copy_history(t_reader *read_data, t_bufstock *begin);
void			down_arrow(t_data *data, t_reader *read_data);
void			up_arrow(t_data *data, t_reader *read_data);
void			alt_arrow(t_data *data, t_reader *read_data);
void			right_arrow(t_data *data, t_reader *read_data);
void			new_line(t_data *data, t_reader *read_data);
void			right_arrow(t_data *data, t_reader *read_data);
void			move_right(t_data *data, t_reader *read_data);
void			move_left(t_data *data, t_reader *read_data);
int				last_col(t_data *data, t_reader *read_data);
void			read_input_buf(t_data *data, t_reader *read_data);

void			debugger(t_data *data);
void			send_informations_to_debugger(t_data *data,
				t_reader *read_data);

void			reprint_after_backspace(t_data *data, t_reader *read_data);
void			completion(t_data *data, t_reader *read_data);

void			create_comp_matching_elem_node(t_completion *comp_data,
				char *matching_word);

t_completion	*create_completion_struct(void);
void			comp_parse_elements(t_data *data, t_reader *read_data,
				t_completion *comp_data);

void			reprint_total(t_data *data, t_reader *read_data,
				t_bufstock *begin);

void			select_part_of_input(t_data *data, t_reader *read_data);

void			extern_paste(t_data *data, t_reader *read_data);
void			paste_clipboard(t_data *data, t_reader *read_data);
void			free_comp_data(t_completion *comp_data);
void			fill_comp_struct_from_hash_tab(t_hash_tab *temp,
				t_completion *comp_data);
void			concat_word_in_buf_and_print_it(t_data *data,
				t_reader *read_data, t_completion *comp_data);

#endif
