/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:25:29 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:25:30 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_all(t_list **stka, t_list **stkb)
{
	t_list	*node;

	node = (*stkb);
	while (node)
	{
		op_push(stka, stkb, 'a');
		node = node->next;
	}
}

void	iter_digit(t_list **stka, t_list **stkb, int power)
{
	t_list	*node;
	int		size;

	node = (*stka);
	size = ft_lstsize((*stka));
	while (size--)
	{
		if ((node->pos / power) % 10 == 0)
			op_push(stkb, stka, 'b');
		else
			op_rotate(stka, 'a');
		node = (*stka);
	}
}

int	sorted(t_list **stk)
{
	t_list	*node;
	t_list	*next;

	node = (*stk);
	next = NULL;
	if (node)
		next = node->next;
	while (next)
	{
		if (node->num > next->num)
			return (-1);
		node = node->next;
		next = node->next;
	}
	return (1);
}
