/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_data_management.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:08:40 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:09 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "input_struct.h"
#include "libft.h"

void			free_comp_data(t_completion *comp_data)
{
	t_comp_matching_element	*temp;

	free(comp_data->path_working_on_cpy);
	free(comp_data->repertory);
	while (comp_data->possibilities_beginning != NULL)
	{
		temp = comp_data->possibilities_beginning;
		comp_data->possibilities_beginning = comp_data->
			possibilities_beginning->next;
		free(temp->matching_word);
		free(temp);
	}
	free(comp_data);
}

void			create_comp_matching_elem_node(t_completion *comp_data,
		char *matching_word)
{
	t_comp_matching_element	*temp;

	if (!(temp = (t_comp_matching_element *)
				malloc(sizeof(t_comp_matching_element))))
		exit(1);
	temp->matching_word = ft_strdup(matching_word);
	temp->is_reg_file = 1;
	temp->next = NULL;
	if (comp_data->possibilities_beginning == NULL)
		comp_data->possibilities_beginning = temp;
	else
		comp_data->ptr_on_possibilities_list->next = temp;
	comp_data->ptr_on_possibilities_list = temp;
}

t_completion	*create_completion_struct(void)
{
	t_completion			*comp_data;

	if (!(comp_data = (t_completion *)malloc(sizeof(t_completion))))
		exit(-1);
	comp_data->ptr_on_slash = NULL;
	comp_data->path_working_on_cpy = NULL;
	comp_data->repertory = NULL;
	comp_data->word_beginning = NULL;
	comp_data->word_begin_index = 0;
	comp_data->nb_of_matching_elements = 0;
	comp_data->current_word_to_comp_size = 0;
	comp_data->possibilities_beginning = NULL;
	comp_data->ptr_on_possibilities_list = NULL;
	return (comp_data);
}
