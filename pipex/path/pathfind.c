#include "../pipex.h"

char	**find_paths(char *envp[])
{
	char	**paths;

	while (*envp != NULL)
	{
		if (ft_strnstr(*envp, "PATH", 50))
			break ;
		envp++;
	}
	paths = ft_split(*envp, ':');
	return (paths);
}

int	check_access(char *path, char *command)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(command) + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, path, ft_strlen(path) + 1);
	ft_strlcat(ptr, command, ft_strlen(path) + ft_strlen(command) + 1);
	if (access(ptr, F_OK) != 0)
		return (0);
	return (1);
}

char	*get_path(char *path, char *command)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(command) + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, path, ft_strlen(path) + 1);
	ft_strlcat(ptr, command, ft_strlen(path) + ft_strlen(command) + 1);
	return (ptr);
}