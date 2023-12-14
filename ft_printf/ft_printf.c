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

static int	count_args(char const *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				i += 2;
			else if (ft_strchr("cspdiuxX", str[i + 1]))
				count++;
		}
	}
	return (count);
}



#include <stdio.h>

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		count;
	int		i;

	i = -1;
	count = count_args(str);
	va_start(arg, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX", str[i + 1]))
		{
			ft_printvar(va_arg(arg, char *), str[i + 1]);
			i++;
		}
		else
			write(1, &str[i], 1);
	}
	return (0);
}
