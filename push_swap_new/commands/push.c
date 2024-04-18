/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:07:22 by dramos-n          #+#    #+#             */
/*   Updated: 2024/04/18 18:07:23 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **pull, t_stack **push)
{
	t_stack	*node;

	if (!(*push))
		return ;
	node = ft_lstnew((*push)->num);
	free(*push);
	*push = (*push)->next;
	ft_lstadd_front(pull, node);
}

void	pa(t_stack **a, t_stack **b, int show)
{
	push(a, b);
	if (show)
		write (1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int show)
{
	push(b, a);
	if (show)
		write (1, "pb\n", 3);
}
