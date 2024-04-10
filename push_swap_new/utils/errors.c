#include "../push_swap.h"

int	repeats_check(t_stack *a, int n)
{
	t_stack	*node;

	node = a;
	while (node)
	{
		if (node->num == n)
			return (0);
		node = node->next;
	}
	return (1);
}

int	syntax_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
