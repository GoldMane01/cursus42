/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:17:25 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/19 15:17:26 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** Writes strings. It's separate from ft_simple because it's used
 * in other places.
*/
int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
		if (write(1, &s[i], 1) == -1)
			return (-1);
	return (1);
}
