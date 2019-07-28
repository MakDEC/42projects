#include <stdio.h>

int main(int argc, char **argv, char **environ)
{
	int		i;

	i = -1;
	while (environ[++i] != NULL)
		printf("%s\n", environ[i]);
	return (0);
}
