#include "../push_swap.h"

void	add_number(t_stack **a, int number)
{
	t_stack	*node;

	node = ft_lstnew(number);
	ft_lstadd_back(a, node);
}

void	init_stack(t_stack **a, char **argv, bool argc)
{
	int	number;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!syntax_check(argv[i]))
			free_all(a, argv, argc);
		number = ft_atoi(argv[i]);
		if (!repeats_check(*a, number))
			free_all(a, argv, argc);
		add_number(a, number);
		i++;
	}
	if (argc)
		free_argv(argv);
}
