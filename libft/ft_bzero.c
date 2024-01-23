/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:00:11 by dramos-n          #+#    #+#             */
/*   Updated: 2023/11/28 13:00:12 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Fills a string with n null chars
void	ft_bzero(void *s, size_t n)
{
	//Auxiliary pointer to not modify the position of *s
	unsigned char	*p;

	p = (unsigned char *) s;
	while (n--)
	{
		*p++ = '\0';
	}
}
