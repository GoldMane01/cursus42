#include "pipex.h"

char	*cmdname(char *s)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s) + ft_strlen("/bin/") + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "/bin/", 6);
	ft_strlcat(str, s, ft_strlen(s) + ft_strlen(str) + 1);
	return (str);
}

char	*cmdalloc(char **params, char **arg, int i)
{
	params[i] = malloc(sizeof(char) * (ft_strlen(arg[i + 1]) + 1));
	if (!params[i])
	{
		free_split(params);
		return (NULL);
	}
	else
	{
		params[i] = arg[i + 1];
		params[i][ft_strlen(arg[i + 1])] = '\0';
	}
	return (params[i]);
}

char	**cmdargs(char **arg)
{
	char	**params;
	int		size;
	int		i;

	size = 0;
	i = 1;
	while (arg[i++])
		size++;
	params = malloc(sizeof(char *) * (size + 1));
	if (!params)
		return (NULL);
	params[size] = NULL;
	i = 0;
	while (arg[i + 1])
	{
		params[i] = cmdalloc(params, arg, i);
		if (!params[i])
			return (NULL);
		i++;
	}
	return (params);
}