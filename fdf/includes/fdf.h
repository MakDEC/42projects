/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 00:22:49 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 01:25:13 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>

typedef struct		s_lines
{
	int				*line;
	int				line_width;
	struct s_lines	*next;
}					t_lines;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_lines	*lines;
	int				height;
	int				x;
	int				y;
	int				h;
	int				x_spacing;
	int				y_spacing;
	int				h_factor;
}					t_data;

int		extract_file(int fd, t_data *data);

#endif
