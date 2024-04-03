/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathget.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:13:07 by dramos-n          #+#    #+#             */
/*   Updated: 2024/03/11 17:13:09 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
