/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:00:54 by dramos-n          #+#    #+#             */
/*   Updated: 2023/11/28 13:00:56 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cdst;
	char	*csrc;
	int		i;

	i = 0;
	if (dst != NULL || src != NULL)
	{
		cdst = (char *) dst;
		csrc = (char *) src;
		while (n > 0)
		{
			cdst[i] = csrc[i];
			i++;
			n--;
		}
	}
	return (dst);
}
