#include <unistd.h>

int main()
{
	sleep (2);
	write(2, "after sleep\n", 12);
	return (0);
}
