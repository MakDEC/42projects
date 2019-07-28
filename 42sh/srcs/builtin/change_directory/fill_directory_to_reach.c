/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_directory_to_reach.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:15:32 by aanger            #+#    #+#             */
/*   Updated: 2019/05/07 14:58:03 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		fill_directory(char **parsed_path, int index, char **directory,
		size_t size_to_malloc)
{
	int			index_bis;

	index_bis = 0;
	if (!(directory[0] = (char *)malloc(sizeof(char) * size_to_malloc)))
		exit(-1);
	ft_bzero(directory[0], size_to_malloc);
	directory[0][0] = '/';
	while (index_bis < index)
	{
		if (parsed_path[index_bis] != NULL)
		{
			if (directory[0][1] != 0)
				ft_strcat(directory[0], "/");
			ft_strcat(directory[0], parsed_path[index_bis]);
			free(parsed_path[index_bis]);
		}
		index_bis++;
	}
	free(parsed_path);
}
