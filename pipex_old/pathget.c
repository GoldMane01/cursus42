/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathget.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:07:07 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/14 16:07:09 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
