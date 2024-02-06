#include "push_swap.h"

#include <stdio.h>

void	init_stack(char *argv[], t_list **stka)
{
	int		i;
	t_list	*node;

	i = 0;
	node = NULL;
	while (argv[++i])
		ft_lstadd_back(stka, ft_lstnew(ft_atoi(argv[i])));
}

int	main(int argc, char *argv[])
{
	t_list	*stka;
	t_list	*stkb;

	stka = NULL;
	stkb = NULL;
	if (!check_input(argc, argv))
		return (0);
	init_stack(argv, &stka);
	return (0);
}
