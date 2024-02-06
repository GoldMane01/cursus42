#include "push_swap.h"

void	op_swap(t_list **head)
{
	int	aux;

	if (!*head || !(*head)->next)
		return ;
	aux = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = aux;
}

void	op_push(t_list **pull, t_list **push)
{
	t_list	*node;

	node = ft_lstnew((*push)->num);
	*push = (*push)->next;
	ft_lstadd_front(pull, node);
}

void	op_rotate(t_list **head)
{
	t_list	*aux;

	aux = *head;
	*head = (*head)->next;
	ft_lstadd_back(head, aux);
}

void	op_rev_rotate(t_list **head)
{
	t_list	*aux;
	t_list	*node;

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
