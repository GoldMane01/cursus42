#include "pipex.h"

void	split_args(char **params, char *args)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 1; //K starts at 1 because the first pointer is the string with the filename
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

char	**get_params(char *file, char *args)
{
	char	**params;
	int		len;

	len = count_strs(args) + 1;
	params = malloc(sizeof(char *) * (len + 1));
	if (!params)
		return (NULL);
	params[0] = get_filename(file);
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

	params = get_params(argv[1], argv[2]);
	execve(argv[1], params, NULL); //I think argv is actually what goes on the first parameter of execve
	if (pipe(fd) == -1)
		return (1);
	//pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		//Child process 1
		params = get_params(argv[1], argv[2]);
		//execve("/usr/bin/ls", params(argv[1], argv[2]), NULL);
	}
	return (0);
}