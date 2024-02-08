#include "push_swap.h"

int	bin_base(int nb)
{
	int	binary;
	int	power;
	int	i;

	i = 0;
	power = 1;
	binary = 0;
	while (nb > 0)
	{
		binary += power * (nb % 2);
		power = power * 10;
		nb = nb / 2;
		i++;
	}
	return (binary);
}

void	turn_binary(t_list **stka)
{
	t_list *node;

	node = (*stka);
	while (node)
	{
		node->pos = bin_base(node->pos);
		node = node->next;
	}
}