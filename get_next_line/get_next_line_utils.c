/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:01:23 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/19 14:01:25 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			ptr = (char *) s;
			return (ptr);
		}
		s++;
	}
	if ((char)c == '\0')
		ptr = (char *) s;
	return (ptr);
}

char	*ft_strcat(char *temp, char *buffer)
{
	char	*join;
	int		i;
	int		j;

	if (buffer)
		join = malloc(sizeof(char) * (len(temp, '\0') + len(buffer, '\0') + 1));
	else
		return (NULL);
	i = -1;
	j = -1;
	while (temp[++i])
		join[i] = temp[i];
	while (buffer[++j])
		join[i] = buffer[j];
	return (join);
}

int	len(char *s, int c)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != c)
			i++;
	}
	return (i);
}
