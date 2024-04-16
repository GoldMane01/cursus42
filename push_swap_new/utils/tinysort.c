#include "../push_swap.h"

void	tiny_sort(t_stack **a)
{
	t_stack	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(a, 1);
	else if ((*a)->next == highest)
		rra(a, 1);
	if ((*a)->num > (*a)->next->num)
		sa(a, 1);
}

void	five_sort(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
	{
		set_all(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}