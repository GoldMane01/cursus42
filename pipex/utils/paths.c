/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:13:00 by dramos-n          #+#    #+#             */
/*   Updated: 2024/03/11 17:13:01 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**find_paths(char *envp[])
{
	char	**paths;

	while (*envp != NULL)
	{
		if (ft_strnstr(*envp, "PATH", 5))
			break ;
		envp++;
	}
	paths = ft_split(*envp, ':');
	return (paths);
}

int	check_access(char *path, char *command)
{
	char	*ptr;
	char	**cmdsplit;

	cmdsplit = ft_split(command, ' ');
	ptr = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmdsplit[0]) + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, path, ft_strlen(path) + 1);
	ft_strlcat(ptr, cmdsplit[0], ft_strlen(path) + ft_strlen(cmdsplit[0]) + 1);
	if (access(ptr, F_OK) != 0)
		return (0);
	return (1);
}

char	*get_path(char *path, char *command)
{
	char	*ptr;
	char	**cmdsplit;

	cmdsplit = ft_split(command, ' ');
	ptr = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmdsplit[0]) + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, path, ft_strlen(path) + 1);
	ft_strlcat(ptr, cmdsplit[0], ft_strlen(path) + ft_strlen(cmdsplit[0]) + 1);
	return (ptr);
}

char	*check_paths(char **allpaths, char *command)
{
	char	*path;

	path = NULL;
	while (*allpaths)
	{
		if (check_access(*allpaths, command))
		{
			path = get_path(*allpaths, command);
			break ;
		}
		allpaths++;
	}
	return (path);
}
