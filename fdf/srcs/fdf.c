/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 21:39:57 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 03:40:59 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "fdf.h"

int	deal_key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(1);
	return (0);	
}

#include <stdio.h>

void	draw_right_line(t_data *data, t_lines *temp)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	double	distance;
	double	hauteur;
	double	recurrence;
	double	i;

	start_x = data->x * data->x_spacing + 100;
	start_y = data->y * data->y_spacing - (temp->line[data->x] * data->h_factor) + 100;
	end_x = (data->x + 1) * data->x_spacing + 100;
	end_y = data->y * data->y_spacing - (temp->line[data->x + 1] * data->h_factor) + 100;
	distance = end_x - start_x;
	hauteur = end_y - start_y;
	if (hauteur != 0)
	{
		recurrence = distance / hauteur;
		/*if (distance % hauteur != 0)
		{
			if (recurrence > 0)
				recurrence++;
			else
				recurrence--;
		}*/
	}
	else
		recurrence = 0;
	printf("recurrence : %f\n", recurrence);
	i = 0;
	while (end_x != start_x)
	{
		if (recurrence != 0 && (i == recurrence || i == -recurrence))
		{
			if (recurrence > 0)
				start_y++;
			else
				start_y--;
			i = 0;
		}
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, start_x, start_y, 0xFFFFFF);
		start_x++;
		i += 0.5;
	}
}

int	draw(t_data *data)
{
	t_lines		*temp;

	temp = data->lines;
	data->x = -1;
	data->y = -1;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1500, 1500, "FdF");
	while (++data->y < data->height)
	{
		while (++data->x < temp->line_width - 1)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x * data->x_spacing + 100,
			(data->y * data->y_spacing) - (temp->line[data->x] * data->h_factor) + 100, 0xFFFFFF);
			draw_right_line(data, temp);
		}
		temp = temp->next;
		data->x = -1;
	}
	mlx_key_hook(data->win_ptr, deal_key, (void *)0);
	mlx_loop(data->mlx_ptr);
	return (1);
}

t_data	*prep_data(t_data *data)
{
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		exit(-1);
	if (!(data->lines = (t_lines*)malloc(sizeof(t_lines))))
		exit(-1);
	data->lines->next = NULL;
	data->height = 0;
	data->x = 0;
	data->y = 0;
	data->h = 0;
	data->x_spacing = 50;
	data->y_spacing = 50;
	data->h_factor = 2;
	return (data);
}

int main(int argc, char **argv)
{
	int		fd;
	t_data	*data;

	if (argc != 2)
	{
		ft_putstr("mauvais usage autiste\n");
		return (-2);
	}
	fd = open(argv[1], O_RDONLY);
	data = NULL;
	data = prep_data(data);
	extract_file(fd, data);
	draw(data);
	close(fd);
	return (0);
}
