#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stka;
	t_stack	*stkb;

	stka = NULL;
	stkb = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack(&stka, argv, argc == 2);
	}
	else
		init_stack(&stka, argv + 1, argc == 2);
}

/* VISUALIZADOR DEL STACK

	t_stack *visual;
	visual = stka;
	while (visual)
	{
		printf("NUM: %d\n", visual->num);
		visual = visual->next;
	}

	printf("---------------------------\n");

	visual = stkb;
	while (visual)
	{
		printf("NUM: %d\n", visual->num);
		visual = visual->next;
	}
*/