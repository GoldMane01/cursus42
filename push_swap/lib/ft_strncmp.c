/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:17:23 by dramos-n          #+#    #+#             */
/*   Updated: 2023/11/29 11:17:24 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	counter;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	counter = 0;
	if (n == 0)
		return (0);
	while (counter < (n - 1) && p1[counter] != '\0' && p2[counter] != '\0')
	{
		if (p1[counter] != p2[counter])
			return (p1[counter] - p2[counter]);
		counter++;
	}
	return (p1[counter] - p2[counter]);
}
