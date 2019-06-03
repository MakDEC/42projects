/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 21:39:57 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 01:26:50 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdio.h>

int	fill_points(char *line, int *points)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		points[j] = 0;
		while (line[i] && line[i] == ' ')
			i++;
		while (line[i] && line[i] != ' ')
		{
			points[j] *= 10;
			points[j] += line[i] - 48;
			i++;
		}
		j++;
	}
	return (1);
}

int		size_to_malloc(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != 0)
	{
		if (line[i] != ' ')
		{
			j++;
			while (line[i] != 0 && line[i] != ' ')
				i++;
		}
		else
			while (line[i] != 0 && line[i] == ' ')
				i++;
	}
	return (j);
}

int		extract_file(int fd, t_data *data)
{
	char	*line;
	int		i;
	t_lines	*temp;
	int		ret_gnl;

	i = 0;
	temp = data->lines;
	ret_gnl = get_next_line(fd, &line);
	while (ret_gnl > 0)
	{
		temp->line_width = size_to_malloc(line);
		if (!(temp->line = (int *)malloc(sizeof(int) * temp->line_width)))
			exit(-1);
		fill_points(line, temp->line);
		free(line);
		i++;
		ret_gnl = get_next_line(fd, &line);
		if (ret_gnl != 0)
		{
			if (!(temp->next = (t_lines*)malloc(sizeof(t_lines))))
				exit(-1);
			temp = temp->next;
			temp->next = NULL;
		}
	}
	data->height = i;
	return (0);
}
