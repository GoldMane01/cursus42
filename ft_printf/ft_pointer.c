/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:59:49 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/16 13:59:50 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Transforms the address in hex
static int	hexptr(unsigned long long n, char *base)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		if (n / 16 != 0)
			len += hexptr((n / 16), base);
		if (write(1, &base[n % 16], 1) == -1)
			return (-1);
		len++;
		n = 0;
	}
	return (len);
}

//Writes the memory address of a pointer in hex
int	print_pointer(void *ptr)
{
	unsigned long long	n;
	int					i;
	int					flag;

	i = 0;
	flag = 1;
	i += print_str("0x");
	if (i == -1)
		return (-1);
	if (!ptr)
	{
		if (print_char('0') == -1)
			return (-1);
		i++;
	}
	else
	{
		n = (unsigned long long)ptr;
		flag = hexptr(n, "0123456789abcdef");
		if (flag == -1)
			return (-1);
		i += flag;
	}
	return (i);
}
