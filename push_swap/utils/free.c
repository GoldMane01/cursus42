/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:08:43 by dramos-n          #+#    #+#             */
/*   Updated: 2024/04/18 18:08:44 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*node;

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
