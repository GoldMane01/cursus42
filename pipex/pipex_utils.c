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
char	*get_filename(char *s)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
