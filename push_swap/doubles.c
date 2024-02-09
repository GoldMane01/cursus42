#include "push_swap.h"

void	op_ss(t_list **stka, t_list **stkb)
{
	op_swap(stka, 'a');
	op_swap(stkb, 'b');
}

void	op_rr(t_list **stka, t_list **stkb)
{
	op_rotate(stka, 'a');
	op_rotate(stkb, 'b');
}

void	op_rrr(t_list **stka, t_list **stkb)
{
	op_rev_rotate(stka, 'a');
	op_rev_rotate(stkb, 'b');
}
