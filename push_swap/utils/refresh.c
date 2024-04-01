#include "../push_swap.h"

void	set_cheapest(t_list *stkb)
{
	int		best_value;
	t_list	*best_node;

	if (!stkb)
		return ;
	best_value = INT_MAX;
	while (stkb)
	{
		if (stkb->price < best_value)
		{
			best_value = stkb->price;
			best_node = stkb;
		}
		stkb = stkb->next;
	}
	best_node->cheapest = true;
}

void	set_positions(t_list **stk)
{
	t_list	*node;
	int		i;
	int		median;

	i = 0;
	median = ft_lstsize(*stk) / 2;
	node = *stk;
	while (node)
	{
		node->pos = i;
		if (i <= median)
			node->above_median = true;
		else
			node->above_median = false;
		i++;
		node = node->next;
	}
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
