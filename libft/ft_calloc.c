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

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned int	n;
	unsigned int	i;

	i = 0;
	n = count * size;
	ptr = (char *)malloc(sizeof(char) * n);
	if (ptr != NULL)
	{
		while (i < n)
		{
			*ptr++ = 0;
			i++;
		}
	}
	ptr -= i;
	return (ptr);
}
