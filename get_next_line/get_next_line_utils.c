#include "get_next_line.h"

char	*line_dup(const char *s, int start, int end)
{
	char			*ptr;
	char			*res;

	ptr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ptr)
		return (NULL);
	res = ptr;
	while (start < end)
	{
		*ptr = s[start++];
		ptr++;
	}
	*ptr = '\0';
	return (res);
}