#include "pipex.h"

void	split_args(char **params, char *args)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
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

char	**get_params(char *args)
{
	char	**params;
	int		len;

	len = count_strs(args);
	params = malloc(sizeof(char *) * (len + 1));
	if (!params)
		return (NULL);
	split_args(params, args);
	params[len] = NULL;
	return (params);
}

int	main(int argc, char *argv[])
{
	int		fd[2];
	int		pid1;
	//int		pid2;
	char	**params;
	char	*cmd;

	if (argc <= 2)
		perror("Too few arguments");
	params = get_params(argv[2]);
	cmd = get_cmd(params[0]);
	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		//Child process 1
		execve(cmd, params, NULL);
	}
	return (0);
}
