#include "push_swap.h"

#include <stdio.h>

void	init_stack(char *argv[], t_list **stka)
{
	int		i;

	i = 0;
	while (argv[++i])
		ft_lstadd_back(stka, ft_lstnew(ft_atoi(argv[i]), -1));
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
	op_swap(&stka, 'a');
printf("STKA------------\n");
t_list *node = (stka);
while (node)
{
	printf("Num: %d, Pos: %d\n", node->num, node->pos);
	node = node->next;
}
printf("STKB------------\n");
t_list *node2 = (stkb);
while (node2)
{
	printf("Num: %d, Pos: %d\n", node2->num, node2->pos);
	node2 = node2->next;
}
printf("----------------------\n");
	op_push(&stkb, &stka, 'a');
printf("STKA------------\n");
node = (stka);
while (node)
{
	printf("Num: %d, Pos: %d\n", node->num, node->pos);
	node = node->next;
}
printf("STKB------------\n");
node2 = (stkb);
while (node2)
{
	printf("Num: %d, Pos: %d\n", node2->num, node2->pos);
	node2 = node2->next;
}
printf("----------------------\n");
	op_push(&stkb, &stka, 'a');
printf("STKA------------\n");
node = (stka);
while (node)
{
	printf("Num: %d, Pos: %d\n", node->num, node->pos);
	node = node->next;
}
printf("STKB------------\n");
node2 = (stkb);
while (node2)
{
	printf("Num: %d, Pos: %d\n", node2->num, node2->pos);
	node2 = node2->next;
}
printf("----------------------\n");
	op_push(&stkb, &stka, 'a');
printf("STKA------------\n");
node = (stka);
while (node)
{
	printf("Num: %d, Pos: %d\n", node->num, node->pos);
	node = node->next;
}
printf("STKB------------\n");
node2 = (stkb);
while (node2)
{
	printf("Num: %d, Pos: %d\n", node2->num, node2->pos);
	node2 = node2->next;
}
printf("----------------------\n");
	op_rotate(&stkb, 'b');
printf("STKA------------\n");
node = (stka);
while (node)
{
	printf("Num: %d, Pos: %d\n", node->num, node->pos);
	node = node->next;
}
printf("STKB------------\n");
node2 = (stkb);
while (node2)
{
	printf("Num: %d, Pos: %d\n", node2->num, node2->pos);
	node2 = node2->next;
}
printf("----------------------\n");
	op_rev_rotate(&stka, 'a');
printf("STKA------------\n");
node = (stka);
while (node)
{
	printf("Num: %d, Pos: %d\n", node->num, node->pos);
	node = node->next;
}
printf("STKB------------\n");
node2 = (stkb);
while (node2)
{
	printf("Num: %d, Pos: %d\n", node2->num, node2->pos);
	node2 = node2->next;
}
printf("----------------------\n");
	op_push(&stka, &stkb, 'b');
printf("STKA------------\n");
node = (stka);
while (node)
{
	printf("Num: %d, Pos: %d\n", node->num, node->pos);
	node = node->next;
}
printf("STKB------------\n");
node2 = (stkb);
while (node2)
{
	printf("Num: %d, Pos: %d\n", node2->num, node2->pos);
	node2 = node2->next;
}
printf("----------------------\n");
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