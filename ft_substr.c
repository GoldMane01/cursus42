#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(len + 1);
	if (ptr)
	{
		while (s[start] != '\0' && len--)
		{
			ptr[i] = s[start];
			start++;
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}