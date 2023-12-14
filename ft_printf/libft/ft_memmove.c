/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:06:07 by dramos-n          #+#    #+#             */
/*   Updated: 2023/11/28 13:06:09 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (dst <= src)
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	else if (dst > src)
	{
		while (len--)
			cdst[len] = csrc[len];
	}
	return (dst);
}
