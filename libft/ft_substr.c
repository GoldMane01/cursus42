/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:55:57 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/03 11:55:59 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Returns a substring of s from start until len.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	/** If start is bigger than the lenght of s I return a pointer with
	 * one \0 char.
	*/
	if (ft_strlen(s) < start)
	{
		ptr = malloc(sizeof(char) * (1));
		if (ptr)
		{
			*ptr = '\0';
			return (ptr);
		}
	}
	else
	{
		/** If the length of the starting point until the end is lower
		 * than len, then only that length is allocated.
		 * If it is not, then only len chars are allocated.
		*/
		if (ft_strlen(s + start) < len)
			len = ft_strlen(s + start);
		if (ft_strlen(s + start) > len)
			ptr = (char *)malloc(sizeof(char) * (len + 1));
		else
			ptr = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
		if (ptr)
			ft_strlcpy(ptr, s + start, len + 1);
	}
	return (ptr);
}
