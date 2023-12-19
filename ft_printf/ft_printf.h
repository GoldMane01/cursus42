/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:28:05 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/14 15:28:07 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		print_str(char *s);
int		print_char(char c);
int		print_int(int d);
int		print_uint(unsigned int u);
int		print_hex(int n, char c);
int		print_pointer(void *ptr);
int		ft_putnbr(int n);
int		ft_putstr(char *s);

#endif
