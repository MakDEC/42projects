#include "../includes/libft.h"
#include <stdio.h>

/*
**	getpgrp() is the  POSIX.1 prefered function to retrieved the proccess group id
*/

int		main(void)
{
	char	buffer[4096];
	int	ret_read;

	ft_bzero(buffer, 4096);
	ret_read = 0;
	if (isatty(0) != 1)
		while ((ret_read = read(0, buffer, 4095)) > 0)
		{
			if (ret_read == -1)
				ft_putstr_fd("error on read\n", 2);
			ft_putstr(buffer);
			ft_bzero(buffer, 4096);
		}
	ft_putstr("Proccess ID = ");
	ft_putendl(ft_itoa((int)getpid()));
	ft_putstr("Process Group ID = ");
	ft_putendl(ft_itoa((int)getpgrp()));
	ft_putstr("Parent Proccess ID = ");
	ft_putendl(ft_itoa((int)getppid()));
	ft_putstr("Session ID = ");
	ft_putendl(ft_itoa((int)getsid(0)));
	return (0);
}
