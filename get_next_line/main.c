#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	int i = 17;
	while (i--)
	{
		//get_next_line(fd);
		printf("... %s\n", get_next_line(fd));
	}
	close(fd);
	return 0;
}