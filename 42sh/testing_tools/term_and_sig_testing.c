#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../includes/libft.h"

int 				main()
{
	struct sigaction	act;
	int			status;
	pid_t			pid;
	char			buf;
	
	if (read(0, &buf, 0) != 0)
	{
		printf("Acces a l'input impossible\n");
	}	
	return (0);
}
