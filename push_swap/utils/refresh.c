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