/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:59:33 by dramos-n          #+#    #+#             */
/*   Updated: 2023/11/28 15:59:34 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Returns a pointer to the last occurrence of the char c in the string s
char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			ptr = (char *) s;
		s++;
	}
	if ((char)c == '\0')
		ptr = (char *) s;
	return (ptr);
}
