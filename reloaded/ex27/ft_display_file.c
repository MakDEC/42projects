/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 02:19:29 by aanger            #+#    #+#             */
/*   Updated: 2018/04/07 01:54:18 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	buff[1];

	fd = 0;
	if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	if (argc < 2)
		write(1, "File name missing.\n", 19);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (read(fd, buff, 1) > 0)
			write(1, buff, 1);
	}
	return (0);
}
