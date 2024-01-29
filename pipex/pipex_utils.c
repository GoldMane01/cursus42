#include "pipex.h"

int	count_strs(char const *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if ((s[i + 1] == ' ' || s[i + 1] == '\0') && s[i] != ' ')
			count++;
		i++;
	}
	return (count);
}

//This function is mostly to malloc memory for the params
char	*get_cmd(char *s)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s) + ft_strlen("/bin/") + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "/bin/", 6);
	ft_strlcat(str, s, ft_strlen(s) + ft_strlen(str) + 1);
	return (str);
}
