/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:54:42 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/22 15:54:45 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**parse_input(char *argv[], int argc)
{
	char	*join;
	char	**nums;
	int		i;

	nums = NULL;
	join = malloc(sizeof(char) * 2);
	if (!join)
		return (NULL);
	join[0] = ' ';
	join[1] = '\0';
	i = 1;
	while (i < argc)
	{
		join = ft_strjoin(join, argv[i]);
		ft_strlcat(join, " ", ft_strlen(join) + ft_strlen(" ") + 1);
		i++;
	}
	nums = ft_split(join, ' ');
	return (nums);
}