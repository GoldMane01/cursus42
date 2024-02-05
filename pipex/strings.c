#include "pipex.h"

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

void	split_args(char **params, char *args)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 1;
	while (args[++i])
	{
		if (args[i] != ' ')
		{
			j = 0;
			while (args[i + j] != ' ' && args[i + j])
				j++;
			params[k++] = ft_substr(args, i, j);
			if (!params[k - 1])
			{
				free_split(params);
				return ;
			}
			i += j - 1;
		}
	}
}

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

char	**get_params(char *file, char *cmd)
{
	char	**params;

	params = malloc(sizeof(char *) * (count_strs(cmd) + 2));
	if (!params)
		return (NULL);
	params[0] = file;
	params[count_strs(cmd) + 1] = NULL;
	split_args(params, cmd);
	return (params);
}
