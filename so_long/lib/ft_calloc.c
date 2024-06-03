/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:18:18 by dramos-n          #+#    #+#             */
/*   Updated: 2023/11/30 12:18:19 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char				*ptr;
	unsigned int		i;

	ptr = (char *)malloc((unsigned int)(count * size));
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < (unsigned int)(count * size))
		*ptr++ = 0;
	//I make the pointer go i steps back to point it at the start
	return (ptr - i);
}
