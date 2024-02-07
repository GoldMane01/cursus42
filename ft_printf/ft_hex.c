/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:07:13 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/16 12:07:14 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Aux function for ft_putnbr_hex. It could probably be joined together
static int	unsigned_base(unsigned int nb, char *base)
{
	int	len;
	int	i;

	len = 0;
	while (nb != 0)
	{
		if (nb / 16 != 0)
		{
			i = unsigned_base((nb / 16), base);
			if (i == -1)
				return (-1);
			len += i;
		}
		if (write(1, &base[nb % 16], 1) == -1)
			return (-1);
		len++;
		nb = 0;
	}
	return (len);
}

//Writes the hex number
static int	ft_putnbr_hex(unsigned int nb, char *base)
{
	int	len;

	len = unsigned_base((nb / 16), base);
	if (len == -1)
		return (-1);
	if (write(1, &base[nb % 16], 1) == -1)
		return (-1);
	len++;
	return (len);
}

//Writes a hex number in either lower or uppercase
int	print_hex(int n, char c)
{
	int	i;

	if (c == 'x')
		i = ft_putnbr_hex(n, "0123456789abcdef");
	else
		i = ft_putnbr_hex(n, "0123456789ABCDEF");
	return (i);
}
