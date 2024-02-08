#include "push_swap.h"

#include <stdio.h>

void	set_pos(t_list **stka, int max, int position)
{
	t_list	*node;

	node = node = (*stka);
	while (node)
	{
		if ((node->num == max) && (node->pos == -1))
		{
			node->pos = position;
			return ;
		}
		node = node->next;
	}
}

int	search_max(t_list **stka)
{
	int		max;

	t_list	*node;

	node = (*stka);
	while (node && node->pos != -1)
		node = node->next;
	max = node->num;
	while (node)
	{
		if (node->pos != -1)
			node = node->next;
		else
		{
			if (node->num > max)
				max = node->num;
			node = node->next;
		}
	}
	return (max);
}

void	position(t_list **stka)
{
	int	i;
	int	max_pos;

	i = ft_lstsize((*stka)) - 1;
	while (i >= 0)
	{
		max_pos = search_max(stka);
		set_pos(stka, max_pos, i);
		i--;
	}
}