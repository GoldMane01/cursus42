/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:08:49 by dramos-n          #+#    #+#             */
/*   Updated: 2024/04/18 18:08:49 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_number(t_stack **a, int number)
{
	t_stack	*node;

	node = ft_lstnew(number);
	ft_lstadd_back(a, node);
}

void	init_stack(t_stack **a, char **argv, bool argc)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!syntax_check(argv[i]))
			free_all(a, argv, argc);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_all(a, argv, argc);
		if (!repeats_check(*a, (int)nbr))
			free_all(a, argv, argc);
		add_number(a, (int)nbr);
		++i;
	}
	if (argc)
		free_argv(argv);
}
