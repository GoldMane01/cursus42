/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:37:54 by dramos-n          #+#    #+#             */
/*   Updated: 2023/11/30 12:37:55 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Returns a duplicate of the string s1
char	*ft_strdup(const char *s1)
{
	char			*ptr;
	char			*res;

	/** Two pointers are created so that while one increses
	 * the other keeps pointing to the start to be returned.
	*/
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	res = ptr;
	if (ptr != NULL)
	{
		while (*s1 != '\0')
		{
			*ptr++ = *s1;
			s1++;
		}
		*ptr = '\0';
	}
	return (res);
}
