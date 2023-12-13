/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:00:55 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/05 13:00:56 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (2);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count + 1);
}

static char	*fill_min(char *ptr)
{
	int	i;
	int	min;

	i = 10;
	min = -2147483648;
	while (i > 0)
	{
		ptr[i--] = ((min % 10) * -1) + '0';
		min = min / 10;
	}
	ptr[0] = '-';
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ptr;

	size = digits(n);
	ptr = malloc(sizeof(char) * (size));
	if (!ptr)
		return (ptr);
	ptr[--size] = '\0';
	if (n == -2147483648)
		return (fill_min(ptr));
	while (size--)
	{
		ptr[size] = ((2 * (n > 0) - 1) * (n % 10)) + '0';
		if (n < 0 && n / 10 == 0)
			ptr[--size] = '-';
		n = n / 10;
	}
	return (ptr);
}
