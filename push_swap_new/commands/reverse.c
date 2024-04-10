#include "../push_swap.h"

void	rev_rotate(t_stack **head)
{
	t_stack	*aux;
	t_stack	*node;

	if (!*head || !(*head)->next)
		return ;
	aux = ft_lstlast(*head);
	node = *head;
	while (node)
	{
		if (!node->next->next)
			node->next = NULL;
		node = node->next;
	}
	ft_lstadd_front(head, aux);
}

void	rra(t_stack **a, int show)
{
	rev_rotate(a);
	if (show)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int show)
{
	rev_rotate(b);
	if (show)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int show)
{
	rev_rotate(a);
	rev_rotate(b);
	if (show)
		write(1, "rrr\n", 4);
}
