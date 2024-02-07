/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:21:08 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/03 14:21:09 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Counts the amount of strings the end array will have.
static size_t	count_strs(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

//Frees every pointer in the array and the array itself
static char	**free_ptr(char	**ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

/** Splits the string s into an array of pointers.
 * Splits the string throught the char c.
*/
char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**ptr;

	i = -1;
	k = 0;
	ptr = malloc(sizeof(char *) * (count_strs(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (s[++i])
	{
		/** When the char c is found on the string
		 * the j var is set to zero and added to i to start
		 * counting from the last char c found.
		*/
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			//If the substring fails the whole array is freed
			ptr[k++] = ft_substr(s, i, j);
			if (!ptr[k - 1])
				return (free_ptr(ptr));
			i += j - 1;
		}
	}
	ptr[k] = NULL;
	return (ptr);
}
