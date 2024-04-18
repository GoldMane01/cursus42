/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:16:46 by dramos-n          #+#    #+#             */
/*   Updated: 2023/11/29 12:16:47 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	get_sign(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	sign;
	long	res;

	res = 0;
	sign = 1;
	while (*str != '\0')
	{
		if ((*str > 8 && *str < 14) || *str == 32)
			str++;
		else
			break ;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (!*str)
		return (-2147483649);
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}
