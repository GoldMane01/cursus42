/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awkhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:30:57 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/19 15:30:58 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_awk(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strnstr(argv[i], "awk", 10))
			return (1);
		i++;
	}
	return (0);
}
