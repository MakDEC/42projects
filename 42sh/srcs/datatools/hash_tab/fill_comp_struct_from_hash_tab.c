/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_comp_struct_from_hash_tab.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:21:09 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:06 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"
#include "input_struct.h"
#include "reader.h"

void		fill_comp_struct_from_hash_tab(t_hash_tab *temp,
		t_completion *comp_data)
{
	int			i;

	i = 0;
	if (temp == NULL)
		return ;
	while (i <= 92)
	{
		if (temp->hash_tab[i] != NULL)
			fill_comp_struct_from_hash_tab(temp->hash_tab[i], comp_data);
		i++;
	}
	if (temp->name != NULL
			&& ft_strncmp(temp->name, comp_data->word_beginning,
				ft_strlen(comp_data->word_beginning)) == 0)
	{
		create_comp_matching_elem_node(comp_data, temp->name);
		comp_data->nb_of_matching_elements++;
	}
}
