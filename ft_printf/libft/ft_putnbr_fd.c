/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:39:19 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/09 16:39:20 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		flag;

	c = '0';
	flag = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n == 0)
			write (fd, &c, 1);
		if (n < 0)
		{
			write (fd, "-", 1);
			n = -n;
		}
		if (n != 0)
		{
			c = (n % 10) + '0';
			if (n / 10 != 0)
				ft_putnbr_fd(n / 10, fd);
			write(fd, &c, 1);
		}
	}
}
