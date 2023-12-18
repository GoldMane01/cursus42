#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static	int	c = 0;
	char		buf[1024];
	int			start;

	if (fd == -1)
		return (NULL);
	read(fd, buf, 1024);
	start = c;
	while (buf[c] != '\n' && buf[c])
		c++;
	line = line_dup(buf, start, c);
	c++;
	return (line);
}