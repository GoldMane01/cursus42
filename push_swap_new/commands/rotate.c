#include "../push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*aux;

	if (!*head || !(*head)->next)
		return ;
	aux = *head;
	*head = (*head)->next;
	ft_lstadd_back(head, aux);
}

void	ra(t_stack **a, int show)
{
	rotate(a);
	if (show)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int show)
{
	rotate(b);
	if (show)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int show)
{
	rotate(a);
	rotate(b);
	if (show)
		write(1, "rr\n", 3);
}
