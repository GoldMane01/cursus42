/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:35:40 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/03 12:35:41 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr)
	{
		ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
		ft_strlcat(ptr, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	}
	return (ptr);
}
