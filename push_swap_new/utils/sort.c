#include "../push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest && *a != cheapest->target)
		rr(a, b, false);
	set_positions(*a);
	set_positions(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest && *a != cheapest->target)
		rrr(a, b, false);
	set_positions(*a);
	set_positions(*b);
}

void	finish_rotation(t_stack **stk, t_stack *top, char stk_c)
{
	while (*stk != top)
	{
		if (stk_c == 'a')
		{
			if (top->above_median)
				ra(stk, 1);
			else
				rra(stk, 1);
		}
		else if (stk_c == 'b')
		{
			if (top->above_median)
				rb(stk, 1);
			else
				rrb(stk, 1);
		}
	}
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target, 'a');
	pa(a, b, 1);
	
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		a_size;
	t_stack	*smallest;

	a_size = ft_lstsize(*a);
	//if (a_size == 5)
	//	five_sort(a, b);
	//else
	//{
		while (a_size-- > 3)
			pb(a, b, 1);
	//}
	tiny_sort(a);
	while (*b)
	{
		set_all(*a, *b);
		move_nodes(a, b);
	}
	set_positions(*a);
	smallest = find_smallest(*a);
	while (*a != smallest)
	{
		if (smallest->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
}