#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	int fd = open("text.txt", O_RDONLY);
	char *line;
	int	lines;

	lines = 1;
	while ((line = get_next_line(fd)))
		printf("%d-> %s\n", lines++, line);
	close(fd);
	return 0;
}