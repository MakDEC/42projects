/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:52:04 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:59:33 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"
#include "input_struct.h"
#include "reader.h"

void		complet_command(t_data *data, t_reader *read_data,
		t_completion *comp_data)
{
	while (read_data->buffers->buffer[comp_data->word_begin_index] == ' ')
		comp_data->word_begin_index++;
	if (read_data->buffers->buffer[comp_data->word_begin_index] == 0)
		return ;
	comp_data->current_word_to_comp_size =
		ft_strlen(&read_data->buffers->buffer[comp_data->word_begin_index]);
	comp_data->word_beginning = ft_strdup(&read_data->buffers->
			buffer[comp_data->word_begin_index]);
	fill_comp_struct_from_hash_tab(data->hash_begin, comp_data);
	if (comp_data != NULL && comp_data->nb_of_matching_elements == 1)
		concat_word_in_buf_and_print_it(data, read_data, comp_data);
	else
		write(1, "\a", 1);
	free(comp_data->word_beginning);
}

void		completion(t_data *data, t_reader *read_data)
{
	t_completion	*comp_data;

	comp_data = create_completion_struct();
	if (read_data->buffers->is_com == 1)
		complet_command(data, read_data, comp_data);
	else
	{
		while (read_data->buffers->buffer[comp_data->word_begin_index]
				&& read_data->buffers->buffer
				[comp_data->word_begin_index] == ' ')
			comp_data->word_begin_index++;
		comp_parse_elements(data, read_data, comp_data);
	}
	free_comp_data(comp_data);
}
