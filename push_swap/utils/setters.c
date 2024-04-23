/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:08:56 by dramos-n          #+#    #+#             */
/*   Updated: 2024/04/18 18:08:57 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_targets(t_stack *a, t_stack *b)
{
	int		best_match;
	t_stack	*target;
	t_stack	*aux;

	while (b)
	{
		best_match = INT_MAX;
		aux = a;
		while (aux)
		{
			if ((aux->num > b->num) && (aux->num < best_match))
			{
				best_match = aux->num;
				target = aux;
			}
			aux = aux->next;
		}
		if (best_match == INT_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_positions(t_stack *stk)
{
	int	i;
	int	median;

	median = ft_lstsize(stk) / 2;
	i = 0;
	while (stk)
	{
		stk->pos = i;
		if (i <= median)
			stk->above_median = true;
		else
			stk->above_median = false;
		i++;
		stk = stk->next;
	}
}

void	set_prices(t_stack *a, t_stack *b)
{
	int	a_size;
	int	b_size;

	a_size = ft_lstsize(a);
	b_size = ft_lstsize(b);
	while (b)
	{
		if (b->above_median)
			b->price = b->pos;
		else
			b->price = (b_size - b->pos);
		if (b->target->above_median)
			b->price += b->target->pos;
		else
			b->price += (a_size - b->target->pos);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	int		cheap_num;
	t_stack	*cheap_node;

	if (b == NULL)
		return ;
	cheap_num = INT_MAX;
	while (b)
	{
		if (b->price < cheap_num)
		{
			cheap_num = b->price;
			cheap_node = b;
		}
		b = b->next;
	}
	cheap_node->cheapest = true;
}

void	set_all(t_stack *a, t_stack *b)
{
	set_positions(a);
	set_positions(b);
	set_targets(a, b);
	set_prices(a, b);
	set_cheapest(b);
}
