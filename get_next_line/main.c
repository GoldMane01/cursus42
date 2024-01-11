#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	int fd = open("texto.txt", O_RDONLY);
	char	*line;
	int i = 2;
	while (i--)
	{
		//printf("%s", get_next_line(fd));
		get_next_line(fd);
	}
	close(fd);
	return 0;
}