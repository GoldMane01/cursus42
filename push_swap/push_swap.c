/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:25:55 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:25:56 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(char *argv[], t_list **stka)
{
	int		i;

	i = -1;
	while (argv[++i])
		ft_lstadd_back(stka, ft_lstnew(ft_atoi(argv[i])));
}

int	main(int argc, char *argv[])
{
	t_list	*stka;
	t_list	*stkb;
	char	**nums;

	stka = NULL;
	stkb = NULL;
	nums = parse_input(argv, argc);
	if (check_input(nums) == -1)
		return (0);
	init_stack(nums, &stka);

	/*
	t_list *node = stka;
	while(node)
	{
		printf("%d,\t%d\n", node->num, node->pos);
		node = node->next;
	}

	printf("--------------------------------------------------\n");

	node = find_smallest(stka);
	printf("%d\n", node->num);
	/*t_list *node2 = stkb;
	while(node2)
	{
		printf("%d,\t%d\n", node2->num, node2->pos);
		node2 = node2->next;
	}*/

	if (ft_lstsize(stka) == 2)
		sort_two(&stka);
	else if (ft_lstsize(stka) == 3)
		sort_three(&stka);
	else
		push_swap(&stka, &stkb);
	return (0);
}
