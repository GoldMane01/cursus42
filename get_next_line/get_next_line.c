/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:01:01 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/19 14:01:02 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*save_rest(char *line, char *temp)
{
	char	*rest;
	int		size;
	int		i;
	int		j;

	if (!line || !temp)
		return (NULL);
	size = (len(temp, '\0') - len(line, '\0')) + 1;
	rest = malloc(sizeof(char) * (size));
	if (!rest)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
		i++;
	if (temp[i] == '\n')
		i++;
	while (temp[i])
		rest[j++] = temp[i++];
	return (rest);
}

char	*get_line(char *s)
{
	char	*res;
	int		i;

	i = 0;
	if (ft_strchr(s, '\n'))
		res = malloc(sizeof(char) * (len(s, '\n') + 1));
	else
		res = malloc(sizeof(char) * (len(s, '\0') + 1));
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*rfile(int fd, char *buffer, char *temp)
{
	int		bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		buffer[bytes] = '\0';
		temp = ft_strcat(temp, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = rfile(fd, buf, temp);
	if (!temp)
		return (NULL);
	line = get_line(temp);
	temp = save_rest(line, temp);
	return (line);
}
