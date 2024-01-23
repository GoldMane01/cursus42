/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:00:55 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/05 13:00:56 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Returns the number of digits a number has and accounts for the '\0' char
 * and the "-" of a negative number.
 */
static int	digits(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (2); //Return 2 because I add space for the '\0' char here
	if (n < 0)
		count++; //Extra space for the "-" sign
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count + 1);
}

//Handles the INT_MIN
static char	*fill_min(char *ptr)
{
	int	i;
	int	min;

	i = 10;
	min = -2147483648;
	while (i)
	{
		ptr[i--] = ((min % 10) * -1) + '0';
		min = min / 10;
	}
	ptr[0] = '-';
	/** I don't null terminate the string because it already is when
	 * I pass it.
	 */
	return (ptr);
}

//Receives an int and returns it as a string
char	*ft_itoa(int n)
{
	int		size;
	char	*ptr;

	size = digits(n);
	ptr = malloc(sizeof(char) * (size));
	if (!ptr)
		return (NULL);
	ptr[--size] = '\0';
	//Handling of INT_MIN
	if (n == -2147483648)
		return (fill_min(ptr));
	while (size--)
	{
		/** "(2 * (n > 0) - 1)" will return 1 or -1.
		 * If n > 0, then the result is 2 * 1 - 1 = 1.
		 * Else, the result is 2 * 0 - 1 = -1.
		 * This way negative numbers are turned into positive.
		 */
		ptr[size] = ((2 * (n > 0) - 1) * (n % 10)) + '0';
		//I add the "-" sign at the end.
		if (n < 0 && n / 10 == 0)
			ptr[--size] = '-';
		n = n / 10;
	}
	return (ptr);
}
