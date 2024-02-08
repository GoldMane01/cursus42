#include "push_swap.h"

#include <stdio.h>

void	init_stack(char *argv[], t_list **stka)
{
	int		i;

	i = 0;
	while (argv[++i])
		ft_lstadd_back(stka, ft_lstnew(ft_atoi(argv[i])));
	position(stka);
	turn_binary(stka);
}

int	main(int argc, char *argv[])
{
	t_list	*stka;
	t_list	*stkb;

	stka = NULL;
	stkb = NULL;
	if (!check_input(argc, argv))
	{
		write(1, "Error", 5);
		return (0);
	}
	init_stack(argv, &stka);
	
	return (0);
}

/*
t_list *node = (stka);
while (node)
{
	printf("Num: %d, Pos: %d\n", node->num, node->pos);
	node = node->next;
}
printf("----------------------\n");
*/