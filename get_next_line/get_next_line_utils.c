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

static char	*line_dup(const char *s, int start, int end)
{
	char			*ptr;
	char			*res;

	ptr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ptr)
		return (NULL);
	res = ptr;
	while (start < end)
	{
		*ptr = s[start++];
		ptr++;
	}
	*ptr = '\0';
	return (res);
}

char	*iterate_line(char *buf, int c)
{
	char		*line;
	int			start;

	start = c;
	if (!buf[c])
		return (NULL);
	if (buf[c] == '\n')
		c++;
	while (buf[c] != '\n')
		c++;
	line = line_dup(buf, start, c);
	c++;
	return (line);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
