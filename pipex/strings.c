#include "pipex.h"

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
	params[size] = NULL;
	i = 0;
	while (arg[i + 1])
	{
		params[i] = arg[i + 1];
		i++;
	}
	return (params);
}