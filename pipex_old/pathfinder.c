/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:07:01 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/14 16:07:02 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_strequal(char *ptr, const char *needle, size_t len)
{
	int	count;

	count = 0;
	while (*needle != '\0' && len > 0)
	{
		if (*ptr != *needle)
			return (0);
		len--;
		ptr++;
		needle++;
		count++;
	}
	if (len == 0 && *needle != '\0')
		return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;

	ptr = (char *)haystack;
	if (*needle == '\0')
		return (ptr);
	while (len > 0 && *haystack != '\0')
	{
		if (*haystack == *needle)
		{
			ptr = (char *)haystack;
			if (check_strequal(ptr, needle, len))
				return (ptr);
		}
		haystack++;
		len--;
	}
	return (0);
}

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
