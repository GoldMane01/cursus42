/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:01:53 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/16 11:01:56 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s)
{
	if (s)
	{
		if (ft_putstr(s) != -1)
			return (ft_strlen(s));
	}
	else
	{
		if (ft_putstr("(null)") != -1)
			return (6);
	}
	return (-1);
}

int	print_char(char c)
{
	if (write(1, &c, 1) != -1)
		return (1);
	return (-1);
}

int	print_int(int d)
{
	char	*s;
	int		len;

	if (d == -2147483648)
		return (print_str("-2147483648"));
	s = ft_itoa(d);
	if (s == NULL)
		return (-1);
	len = print_str(s);
	free(s);
	return (len);
}

int	print_uint(unsigned int n)
{
	int		i;
	char	c;
	int		j;

	i = 1;
	c = '0';
	if (n == 0)
		if (write (1, &c, 1) == -1)
			return (-1);
	if (n != 0)
	{
		c = (n % 10) + '0';
		if (n / 10 != 0)
		{
			j = print_uint(n / 10);
			if (j == -1)
				return (-1);
			i += j;
		}
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (i);
}
