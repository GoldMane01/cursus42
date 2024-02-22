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

void	radix_sort(t_list **stka, t_list **stkb)
{
	int	power;

	power = 1;
	while (sorted(stka) == -1)
	{
		iter_digit(stka, stkb, power);
		power = power * 10;
		push_all(stka, stkb);
	}
}

void	sort_two(t_list **stk)
{
	t_list	*node;

	node = (*stk);
	if (node->num > node->next->num)
		op_swap(stk, 'a');
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
		op_swap(stk, 'a');
		op_rotate(stk, 'a');
	}
	if (first > second && first < third)
		op_swap(stk, 'a');
	if (first < second && first > third)
		op_rev_rotate(stk, 'a');
	if (first > second && second < third && first > third)
		op_rotate(stk, 'a');
	if (first > second && second > third)
	{
		op_swap(stk, 'a');
		op_rev_rotate(stk, 'a');
	}
}
