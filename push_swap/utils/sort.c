/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:24:53 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/15 15:24:54 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_list **stk)
{
	t_list	*node;

	node = (*stk);
	if (node->num > node->next->num)
		op_swap(stk, 'a', 1);
}

void	sort_three(t_list **stk)
{
	int	first;
	int	second;
	int	third;

	first = (*stk)->num;
	second = (*stk)->next->num;
	third = (*stk)->next->next->num;
	if (sorted(stk) != -1)
		return ;
	if (first < second && first < third)
	{
		op_swap(stk, 'a', 1);
		op_rotate(stk, 'a', 1);
	}
	if (first > second && first < third)
		op_swap(stk, 'a', 1);
	if (first < second && first > third)
		op_rev_rotate(stk, 'a', 1);
	if (first > second && second < third && first > third)
		op_rotate(stk, 'a', 1);
	if (first > second && second > third)
	{
		op_swap(stk, 'a', 1);
		op_rev_rotate(stk, 'a', 1);
	}
}

void	sort_five(t_list **stka, t_list **stkb)
{
	while (ft_lstsize(*stka) > 3)
	{
		refresh_nodes(*stka, *stkb);
		finish_rotation(stka, find_smallest(*stka), 'a');
		op_push(stkb, stka, 'b', 1);
	}
}

void	push_swap(t_list **stka, t_list **stkb)
{
	int		size_a;
	t_list	*smallest;

	size_a = ft_lstsize(*stka);
	if (size_a == 5)
		sort_five(stka, stkb);
	else
	{
		while (size_a-- > 3)
			op_push(stkb, stka, 'b', 1);
	}
	sort_three(stka);
	while(*stkb)
	{
		refresh_nodes(*stka, *stkb);
		move_nodes(stka, stkb);
	}
	set_positions(stka);
	smallest = find_smallest(*stka);
	if (smallest->above_median)
		while (*stka != smallest)
			op_rotate(stka, 'a', 1);
	else
		while (*stka != smallest)
			op_rev_rotate(stka, 'a', 1);
}
