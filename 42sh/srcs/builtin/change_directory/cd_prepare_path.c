/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_prepare_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:03:55 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 05:24:07 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cd.h"

static void		logically_analyse_of_path(char **parsed_path, int *index,
				int *index_bis)
{
	while (parsed_path[*index] != NULL)
	{
		if (ft_strcmp(parsed_path[*index], "..") == 0)
		{
			if (*index > 0)
			{
				*index_bis = *index - 1;
				while (*index_bis > 0 && parsed_path[*index_bis] == NULL)
					(*index_bis)--;
				if (parsed_path[*index_bis] != NULL)
				{
					free(parsed_path[*index_bis]);
					parsed_path[*index_bis] = NULL;
				}
			}
			free(parsed_path[*index]);
			parsed_path[*index] = NULL;
		}
		else if (ft_strcmp(parsed_path[*index], ".") == 0)
		{
			free(parsed_path[*index]);
			parsed_path[*index] = NULL;
		}
		(*index)++;
	}
}

char			*prepare_directory_from_relative_path(
						t_data *data,
						t_cd_variables *cd_vars,
						t_params_list *params_list)
{
	char		*directory;
	char		**parsed_path;
	int			index;
	int			index_bis;
	size_t		size_to_malloc;

	index = 0;
	index_bis = 0;
	size_to_malloc = 2;
	parsed_path = prepare_parsed_path(data, cd_vars, params_list);
	if (parsed_path == NULL)
		return (NULL);
	if (cd_vars->mode == 0)
		logically_analyse_of_path(parsed_path, &index, &index_bis);
	else
		while (parsed_path[index] != NULL)
			index++;
	index_bis = -1;
	while (++index_bis < index)
	{
		if (parsed_path[index_bis] != NULL)
			size_to_malloc += ft_strlen(parsed_path[index_bis]) + 1;
	}
	fill_directory(parsed_path, index, &directory, size_to_malloc);
	return (directory);
}

char			*prepare_directory_from_absoluth_path(
						t_cd_variables *cd_vars,
						t_params_list *params_list)
{
	char		*directory;
	char		**parsed_path;
	int			index;
	int			index_bis;
	size_t		size_to_malloc;

	index = 0;
	index_bis = 0;
	size_to_malloc = 2;
	parsed_path = ft_strsplit(params_list->params[cd_vars->directory_position],
				'/');
	if (cd_vars->mode == 0)
		logically_analyse_of_path(parsed_path, &index, &index_bis);
	else
		while (parsed_path[index] != NULL)
			index++;
	index_bis = 0;
	while (index_bis < index)
	{
		if (parsed_path[index_bis] != NULL)
			size_to_malloc += ft_strlen(parsed_path[index_bis]) + 1;
		index_bis++;
	}
	fill_directory(parsed_path, index, &directory, size_to_malloc);
	return (directory);
}
