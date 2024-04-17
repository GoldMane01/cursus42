/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:51:54 by dramos-n          #+#    #+#             */
/*   Updated: 2024/03/12 16:51:55 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	operate(char *op, t_stack **stka, t_stack **stkb)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		sa(stka, 0);
	else if (ft_strncmp(op, "sb", 2) == 0)
		sb(stkb, 0);
	else if (ft_strncmp(op, "ra", 2) == 0)
		ra(stka, 0);
	else if (ft_strncmp(op, "rba", 2) == 0)
		rb(stkb, 0);
	else if (ft_strncmp(op, "pb", 2) == 0)
		pb(stka, stkb, 0);
	else if (ft_strncmp(op, "pa", 2) == 0)
		pa(stka, stkb, 0);
	else if (ft_strncmp(op, "rra", 3) == 0)
		rra(stka, 0);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		rrb(stkb, 0);
	else
		return (-1);
	return (1);
}

void	write_ok(t_stack *stka)
{
	if (sorted(&stka) != -1)
		write(1, "OK", 2);
	else
		write (1, "KO", 2);
}

int	main(int argc, char *argv[])
{
	char	*op;
	t_stack	*stka;
	t_stack	*stkb;

	stkb = NULL;
	stka = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack(&stka, argv, argc == 2);
	}
	else
		init_stack(&stka, argv + 1, argc == 2);
	op = "0";
	while (op)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		op = ft_strtrim(op, "\n");
		if (operate(op, &stka, &stkb) == -1)
			return (0);
	}
	write_ok(stka);
	return (0);
}
