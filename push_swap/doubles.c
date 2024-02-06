#include "push_swap.h"

void	op_ss(t_list **stka, t_list **stkb)
{
	op_swap(stka);
	op_swap(stkb);
}

void	op_rr(t_list **stka, t_list **stkb)
{
	op_rotate(stka);
	op_rotate(stkb);
}

void	op_rrr(t_list **stka, t_list **stkb)
{
	op_rev_rotate(stka);
	op_rev_rotate(stkb);
}
