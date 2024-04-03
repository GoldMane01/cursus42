/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:12:15 by dramos-n          #+#    #+#             */
/*   Updated: 2024/03/11 17:12:16 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	last_command(char **commands, int cmdnum)
{
	int	i;

	i = 0;
	while (commands[i])
		i++;
	if (i == cmdnum + 1)
		return (1);
	return (0);
}
