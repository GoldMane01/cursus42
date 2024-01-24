#include "pipex.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize <= 0)
		return (i);
	while (src[count] != '\0' && count < (dstsize - 1))
	{
		dst[count] = src[count];
		count++;
	}
	if (dstsize)
		dst[count] = '\0';
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		ptr = malloc(sizeof(char) * (1));
		if (ptr)
		{
			*ptr = '\0';
			return (ptr);
		}
	}
	else
	{
		if (ft_strlen(s + start) < len)
			len = ft_strlen(s + start);
		if (ft_strlen(s + start) > len)
			ptr = (char *)malloc(sizeof(char) * (len + 1));
		else
			ptr = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
		if (ptr)
			ft_strlcpy(ptr, s + start, len + 1);
	}
	return (ptr);
}