/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:16:46 by dramos-n          #+#    #+#             */
/*   Updated: 2023/11/29 12:16:47 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Receives a string and turns it into an int 
int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	while (*str != '\0')
	{
		//Skips any space characters
		if ((*str > 8 && *str < 14) || *str == 32)
			str++;
		else
			break ;
	}
	//Skips any "+" character and changes the sign for any "-" character
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		//Builds the number by multiplying by 10 and adding the next char
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}
