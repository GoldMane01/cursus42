/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:41:49 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/03 13:41:50 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Deltes the chars in the set from the start and end of s1.
 * It stops deleting from each side once it finds a char that
 * isn't in the set.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;

	//The var i is the start and j is the end
	i = 0;
	j = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	/** First I check how many chars I need to delete from the start.
	 * If i becomes higher than j, it means the entire string is to
	 * be deleted and a pointer no \0 is returned.
	*/
	while (ft_strchr(set, s1[i]) && i <= j)
		i++;
	if (i > j)
		return (ft_strdup(s1 + j + 1));
	//I check how many chars I need to delete from the end.
	while (ft_strchr(set, s1[j]) && j >= 0)
		j--;
	ptr = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!ptr)
		return (NULL);
	/** Finally I increase s1 to point to the new start
	 * and copy from there until the new end.
	*/
	s1 += i;
	ft_strlcpy(ptr, s1, j - i + 2);
	return (ptr);
}
