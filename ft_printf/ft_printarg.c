/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:38:27 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/14 15:38:28 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printarg(char *str, char c)
{
	if (c == 's')
		ft_putstr_fd(str, 1);
	if (c == 'c')
		ft_putchar_fd(*str, 1);
	if (c == 'd')
		ft_putnbr_fd(ft_atoi(str), 1);
}
