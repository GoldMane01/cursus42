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

char	*get_next_line(int fd)
{
	static char	*line;
	int			c;
	char		buf[BUFFER_SIZE];
	int			eof;

	c = 0;
	eof = read(fd, buf, BUFFER_SIZE);
	if (eof != 0)
	{
		c = reach_nl(buf, eof);
		if (c > 0)
		{
			line = malloc(sizeof(char) * (c + 1));
			if (!line)
				return (NULL);
			ft_strcat(line, buf, c);
		}
	}
	return (line);
}
