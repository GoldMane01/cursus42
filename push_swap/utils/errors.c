/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:25:22 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:25:24 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_repeats(char **nums)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nums[i] && nums[i + 1])
	{
		j = i + 1;
		while (nums[j])
		{
			if (ft_strncmp(nums[i], nums[j], 10) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_chars(char *s)
{
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			s++;
		else
			return (-1);
	}
	return (1);
}

int	check_count(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		i++;
	}
	return (i);
}

int	check_input(char **nums)
{
	int	i;

	i = -1;
	if (check_count(nums) < 2)
	{
		write(STDERR_FILENO, "Too few arguments\n", 18);
		return (-1);
	}
	while (nums[++i])
	{
		if (check_chars(nums[i]) == -1)
		{
			write(STDERR_FILENO, "Bad input\n", 10);
			return (-1);
		}
	}
	if (check_repeats(nums) == -1)
	{
		write(STDERR_FILENO, "Duplicate numbers\n", 18);
		return (-1);
	}
	return (1);
}
