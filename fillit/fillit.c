/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:44:05 by aanger            #+#    #+#             */
/*   Updated: 2018/04/23 07:48:22 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (write(1, "usage: ./fillit file\n", 21));
	fd = open(argv[1], O_RDONLY);
	if (ft_read_file(fd) == 0)
		write(1, "error\n", 6);
	return (0);
}
