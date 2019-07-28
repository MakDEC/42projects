#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	sigint_handler()
{
	printf("Dans le sigint handler locale\n");
	return ;
}

int main()
{
	char	buffer[4097];

	signal(SIGINT, sigint_handler);
	bzero(buffer, 4097);
	while (read(0, buffer, 4096) > 0)
	{
		printf("Apres read\n");
	}
	return (0);
}
