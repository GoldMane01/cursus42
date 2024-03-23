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
	op_ss(stka, stkb);
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


	/*set_positions(stka);
	set_positions(stkb);
	set_price(*stka, *stkb);
	t_list *node = *stkb;
	while(node)
	{
		printf("%d,\t%d,\t%d\n", node->num, node->pos, node->price);
		node = node->next;
	}*/

}

void	set_price(t_list *stka, t_list *stkb)
{
	while (stkb)
	{
		stkb->price = stkb->pos;
		if (!(stkb->above_median))
			stkb->price = ft_lstsize(stkb) - (stkb->pos);
		if (stkb->target->above_median)
			stkb->price += stkb->target->pos;
		else
			stkb->price += ft_lstsize(stka) - (stkb->target->pos);
		stkb = stkb->next;
	}
}

t_list	*find_smallest(t_list *stk)
{
	t_list	*node;
	int		smallest;

	smallest = INT_MAX;
	while (stk)
	{
		if (stk->num < smallest)
		{
			smallest = stk->num;
			node = stk;
		}
		stk = stk->next;
	}
	return (node);
}

void	set_target(t_list *stka, t_list *stkb)
{
	t_list	*current;
	t_list	*ntarget;
	int		max;

	while (stkb)
	{
		max = INT_MAX;
		current = stka;
		while (current)
		{
			if (current->num > stkb->num && current->num < max)
			{
				max = current->num;
				ntarget = current;
			}
			current = current->next;
		}
		if (INT_MAX == max)
			stkb->target = find_smallest(stka);
		else
			stkb->target = ntarget;
		stkb = stkb->next;
	}
}
