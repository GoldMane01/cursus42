/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:09:48 by dramos-n          #+#    #+#             */
/*   Updated: 2024/04/18 18:09:49 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stka;
	t_stack	*stkb;

	stka = NULL;
	stkb = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	init_stack(&stka, argv + 1, 2 == argc);
	if (!sorted(&stka))
	{
		if (ft_lstsize(stka) == 2)
			sa(&stka, 1);
		else if (ft_lstsize(stka) == 3)
			tiny_sort(&stka);
		else
			push_swap(&stka, &stkb);
	}
	free_stack(&stka);
	return (0);
}
