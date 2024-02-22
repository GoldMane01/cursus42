/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:26:02 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:26:03 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_swap(t_list **head, int c)
{
	int	aux;

	if (!*head || !(*head)->next)
		return ;
	aux = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = aux;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	op_push(t_list **pull, t_list **push, int c)
{
	t_list	*node;

	if (!(*push))
		return ;
	node = ft_lstnew((*push)->num, (*push)->pos);
	*push = (*push)->next;
	ft_lstadd_front(pull, node);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	op_rotate(t_list **head, int c)
{
	t_list	*aux;

	if (!*head || !(*head)->next)
		return ;
	aux = *head;
	*head = (*head)->next;
	ft_lstadd_back(head, aux);
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	op_rev_rotate(t_list **head, int c)
{
	t_list	*aux;
	t_list	*node;

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
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
