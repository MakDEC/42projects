/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:12:50 by aanger            #+#    #+#             */
/*   Updated: 2018/04/22 01:22:17 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int				ft_read_file(int fd);
int				ft_initialize_map(unsigned long long tab[5][27]);
int				ft_backtracking(unsigned long long tab[5][27], unsigned long
		long map[4], unsigned long long cpytab[5][27], int size);
int				ft_option3bis(unsigned long long tab[5][27], unsigned long
		long cpytab[5][27], int i, unsigned long long map[4]);
void			ft_draw(unsigned long long tab[5][27], int size, int nbrtetri);

#endif
