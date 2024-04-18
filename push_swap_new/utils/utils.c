/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:09:18 by dramos-n          #+#    #+#             */
/*   Updated: 2024/04/18 18:09:19 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_smallest(t_stack *a)
{
	t_stack	*lowest_node;

	lowest_node = a;
	while (a)
	{
		if (a->num < lowest_node->num)
			lowest_node = a;
		a = a->next;
	}
	return (lowest_node);
}

t_stack	*find_highest(t_stack *a)
{
	t_stack	*highest_node;

	highest_node = a;
	while (a)
	{
		if (a->num > highest_node->num)
			highest_node = a;
		a = a->next;
	}
	return (highest_node);
}

int	sorted(t_stack **stk)
{
	t_stack	*node;
	t_stack	*next;

	node = (*stk);
	next = NULL;
	if (node)
		next = node->next;
	while (next)
	{
		if (node->num > next->num)
			return (0);
		node = node->next;
		next = node->next;
	}
	return (1);
}

t_stack	*find_cheapest(t_stack *stk)
{
	if (stk == NULL)
		return (NULL);
	while (stk)
	{
		if (stk->cheapest)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}
