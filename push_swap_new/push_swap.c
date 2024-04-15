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
	if (!sorted(&stka))
	{
		if (ft_lstsize(stka) == 2)
			sa(&stka, 1);
		else if (ft_lstsize(stka) == 3)
			tiny_sort(&stka);
		else
			push_swap(&stka, &stkb);
	}
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



	pb(&stka, &stkb, 0);
	pb(&stka, &stkb, 0);
	pb(&stka, &stkb, 0);
	pb(&stka, &stkb, 0);
	pb(&stka, &stkb, 0);
	pb(&stka, &stkb, 0);
	pb(&stka, &stkb, 0);
	pb(&stka, &stkb, 0);
	pb(&stka, &stkb, 0);
	tiny_sort(&stka);
	set_all(stka, stkb);

	t_stack *visual;
	visual = stka;
	while (visual)
	{
		printf("%d: Price-> %d, Num-> %d\n", visual->pos, visual->price, visual->num);
		visual = visual->next;
	}

	printf("---------------------------\n");

	visual = stkb;
	while (visual)
	{
		printf("%d: Price-> %d, Target-> %d, Num-> %d, Cheapest-> %d\n", visual->pos, visual->price, visual->target->num, visual->num, visual->cheapest);
		visual = visual->next;
	}

*/