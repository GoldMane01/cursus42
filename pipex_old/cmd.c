/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:16:20 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:16:22 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*cmdname(char *s, char *envp[])
{
	char	**allpaths;
	char	*path;
	char	*command;

	allpaths = find_paths(envp);
	*allpaths += 5;
	command = malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (!command)
		return (NULL);
	ft_strlcpy(command, "/", 2);
	ft_strlcat(command, s, ft_strlen(s) + ft_strlen(command) + 1);
	path = check_paths(allpaths, command);
	return (path);
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
