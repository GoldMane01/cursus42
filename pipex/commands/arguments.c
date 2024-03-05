#include "../pipex.h"

void	free_split(char **params)
{
	int	i;

	i = 0;
	while (params[i])
	{
		free(params[i]);
		i++;
	}
	free(params);
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