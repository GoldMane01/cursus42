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

int	reach_nl(char *buf, int eof)
{
	int	i;

	i = 0;
	while (eof-- && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i);
	return (0);
}

void	ft_strcat(char *line, char *buf, int c)
{
	int		i;
	char	*ptr;

	i = -1;
	ptr = line;
	while (++i <= c)
	{
		*line = *buf;
		line++;
		buf++;
	}
	*line = '\0';
	printf("%s\n", ptr);
}