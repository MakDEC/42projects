/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:32:14 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:09 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "input_struct.h"
#include "reader.h"
#include "libft.h"
#include <dirent.h>
#include <term.h>

static int		extract_matching_elements(t_data *data, t_reader *read_data,
		t_completion *comp_data)
{
	DIR				*rep;
	struct dirent	*readfile;

	if ((rep = opendir(comp_data->repertory)) == NULL)
		return (-1);
	while ((readfile = readdir(rep)) != NULL)
		if (ft_strncmp(comp_data->word_beginning, readfile->d_name,
					comp_data->current_word_to_comp_size) == 0)
		{
			create_comp_matching_elem_node(comp_data, readfile->d_name);
			if (readfile->d_type != DT_REG)
				comp_data->ptr_on_possibilities_list->is_reg_file = 0;
			comp_data->nb_of_matching_elements++;
		}
	if (comp_data->nb_of_matching_elements == 1)
		concat_word_in_buf_and_print_it(data, read_data, comp_data);
	closedir(rep);
	return (comp_data->nb_of_matching_elements);
}

void			comp_parse_elements(t_data *data, t_reader *read_data,
		t_completion *comp_data)
{
	comp_data->path_working_on_cpy = ft_strdup(
			&read_data->buffers->buffer[comp_data->word_begin_index]);
	comp_data->ptr_on_slash = ft_strrchr(comp_data->path_working_on_cpy, '/');
	if (comp_data->ptr_on_slash != comp_data->path_working_on_cpy
			&& *comp_data->ptr_on_slash == '/')
	{
		*comp_data->ptr_on_slash = 0;
		comp_data->repertory = ft_strdup(comp_data->path_working_on_cpy);
		comp_data->word_beginning = comp_data->ptr_on_slash + 1;
	}
	else
	{
		comp_data->repertory = ft_strdup(".");
		comp_data->word_beginning = comp_data->path_working_on_cpy;
	}
	comp_data->current_word_to_comp_size = ft_strlen(comp_data->word_beginning);
	if (access(comp_data->repertory, R_OK) == -1
			|| extract_matching_elements(data, read_data, comp_data) < 1)
		write(1, "\a", 1);
}
