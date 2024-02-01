#include "pipex.h"

int main(void)
{
	int fd = open("temp", O_RDONLY | O_CREAT);

	if (!access("temp", O_RDWR))
	{
		printf("Ennove");
	}
	else
	{
		printf("Boff");
	}

	unlink("temp");
}