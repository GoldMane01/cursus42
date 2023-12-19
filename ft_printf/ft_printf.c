/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:27:42 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/14 15:27:48 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printvar(va_list arg, char c)
{
	if (c == 's')
		return (print_str(va_arg(arg, char *)));
	else if (c == 'c')
		return (print_char(va_arg(arg, int)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(arg, int)));
	else if (c == 'u')
		return (print_uint(va_arg(arg, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (print_hex(va_arg(arg, int), c));
	else if (c == 'p')
		return (print_pointer(va_arg(arg, void *)));
	else
		return (print_char(c));
}

int	end(va_list arg, int n)
{
	va_end(arg);
	return (n);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		len;
	int		j;

	len = 0;
	i = -1;
	va_start(arg, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			j = printvar(arg, str[++i]);
			if (j == -1)
				return (end(arg, -1));
			len += j - 1;
		}
		else
		{
			if (write(1, &str[i], 1) == -1)
				return (end(arg, -1));
		}
		len++;
	}
	return (end(arg, len));
}
