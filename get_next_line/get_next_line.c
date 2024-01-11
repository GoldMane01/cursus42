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

char	*get_line(char *line, char *rest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(rest[i] && rest[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while(rest[j] && rest[j] != '\n')
	{
		line[j] = rest[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*save_text(char *rest, char *buffer)
{
	char	*join;
	int		i;
	int		j;

	join = malloc(sizeof(char) * (slen(rest) + slen(buffer) + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	if (rest)
	{
		while (rest[i++])
			join[i] = rest[i];
	}
	if (buffer)
	{
		while (buffer[j++])
			join[i++] = buffer[j];
	}
	join[i] = '\0';
	free(rest);
	return (join);
}

char	*read_file(int fd, char *rest)
{
	int		bytes;
	int		nl;
	char	buffer[BUFFER_SIZE + 1];

	bytes = 1;
	nl = 0;
	if (slen(rest) == 0)
	{
		while (!nl && bytes != 0)
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes < 0)
				return (NULL);
			buffer[bytes] = '\0';
			rest = save_text(rest, buffer);
			if (!rest)
				return (NULL);
			nl = find_nl(rest);
		}
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	char static	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_file(fd, rest))
		return (NULL);
	line = get_line(line, rest);
	return (line);
}
