/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:36:07 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 00:16:57 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"
#include <stdlib.h>

void				multi_path(t_hash_tab *temp, char *current_path,
		char *name, int size_to_malloc)
{
	char			*temp_char;

	size_to_malloc += ft_strlen(temp->path) + 2;
	if (!(temp_char = (char*)malloc(sizeof(char) * size_to_malloc)))
		exit(-1);
	ft_bzero(temp_char, size_to_malloc);
	ft_strcat(temp_char, "*");
	ft_strcat(temp_char, temp->path);
	ft_strcat(temp_char, "*");
	ft_strcat(temp_char, current_path);
	ft_strcat(temp_char, "/");
	ft_strcat(temp_char, name);
	free(temp->path);
	temp->path = temp_char;
}
