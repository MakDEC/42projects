/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:49:13 by aanger            #+#    #+#             */
/*   Updated: 2019/05/05 17:05:54 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_STRUCT_H
# define INPUT_STRUCT_H

# include <stddef.h>

typedef struct					s_select_data
{
	struct s_select_char		*select_begin;
	struct s_select_char		*select_current_case;
	struct s_bufstock			*current_buffer;
	size_t						selection_len;
	int							line_i;
	int							cur_buf_i;
}								t_select_data;

typedef struct					s_select_char
{
	char						character;
	struct s_select_char		*previous;
	struct s_select_char		*next;
}								t_select_char;

typedef struct					s_comp_matching_elem
{
	char						*matching_word;
	int							is_reg_file;
	struct s_comp_matching_elem	*next;
}								t_comp_matching_element;

typedef struct					s_completion
{
	char						*ptr_on_slash;
	char						*path_working_on_cpy;
	char						*repertory;
	char						*word_beginning;
	int							word_begin_index;
	int							nb_of_matching_elements;
	size_t						current_word_to_comp_size;
	struct s_comp_matching_elem	*possibilities_beginning;
	struct s_comp_matching_elem	*ptr_on_possibilities_list;
}								t_completion;

typedef struct					s_temp
{
	struct s_bufstock			*buffers;
	struct s_bufstock			*begin;
	int							i;
}								t_temp;

/*
**		Words structure, content :
**			-a char* (the word)
**			-the current position on this word
**			-an int to indicate if the word should be a command
**			-a pointer on previous node
**			-a pointer on next node
*/
typedef struct					s_bufstock
{
	char						*buffer;
	int							buf_i;
	int							is_com;
	int							line;
	struct s_bufstock			*previous;
	struct s_bufstock			*next;
}								t_bufstock;

/*
**		Reading input structure, content :
**			-a pointer on current word
**			-a pointer on the beginning word
**			-a buf used for read
**			-the first col of first line (total col - prompt size)
**			-a pointer containing of line indexs
**			-an int used to capture the return of read
**			-an int used to know when enter or ctrl D is pressed
**			-temporary pointer for historic and words
*/
typedef struct					s_reader
{
	struct s_bufstock			*buffers;
	struct s_bufstock			*begin;
	char						input_buf[8];
	int							initiale_cursor_position[2];
	int							col_line_0;
	int							line_i;
	int							ret_read;
	int							ret_read_buf;
	struct s_history			*temp_his;
	struct s_temp				*temp;
}								t_reader;

#endif
