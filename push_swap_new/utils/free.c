#include "../push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_stack(t_stack **stack)
{
	t_stack *tmp;
	t_stack *node;

	if (stack == NULL)
		return ;
	node = *stack;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

void	free_all(t_stack **a, char **argv, bool argc)
{
	free_stack(a);
	if (argc)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}
