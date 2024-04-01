#include "../push_swap.h"

void	move_nodes(t_list **stka, t_list **stkb)
{
	t_list	*cheap;

	cheap = get_cheapest(*stkb);
	if (cheap->above_median && cheap->target->above_median)
		rotate_both(stka, stkb, cheap);
	else if (!(cheap->above_median) && !(cheap->target->above_median))
		reverse_rotate_both(stka, stkb, cheap);
	finish_rotation(stkb, cheap, 'b');
	finish_rotation(stka, cheap->target, 'a');
	op_push(stka, stkb, 'a', 1);
}

void	rotate_both(t_list **stka, t_list **stkb, t_list *cheap)
{
	while (*stka != cheap->target && *stkb != cheap)
		op_rr(stka, stkb);
	set_positions(stka);
	set_positions(stkb);
}

void	reverse_rotate_both(t_list **stka, t_list **stkb, t_list *cheap)
{
	while (*stka != cheap->target && *stkb != cheap)
		op_rrr(stka, stkb);
	set_positions(stka);
	set_positions(stkb);
}

void	finish_rotation(t_list **stk, t_list *top, char stk_char)
{
	while (*stk != top)
	{
		if (top->above_median)
			op_rotate(stk, stk_char, 1);
		else
			op_rev_rotate(stk, stk_char, 1);
	}
}
