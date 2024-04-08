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

int	check_repeats(t_list **stka)
{
	t_list	*head;
	t_list	*node;

	head = *stka;
	node = (*stka)->next;
	while(head)
	{
		while (node)
		{
			if (head->num == node->num)
				return (-1);
			node = node->next;
		}
		head = head->next;
		if (head != NULL)
			node = head->next;
	}
	return (1);
}

int	check_chars(char *s)
{
	if (*s == '-')
		s++;
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

int	check_input(char **nums, t_list **stka)
{
	int	i;

	i = -1;
	if (check_count(nums) < 2)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	while (nums[++i])
	{
		if (check_chars(nums[i]) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	if (check_repeats(stka) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (1);
}
