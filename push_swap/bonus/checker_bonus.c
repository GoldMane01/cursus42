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

#include "checker_bonus.h"

int	operate(char *op, t_list **stka, t_list **stkb)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		op_swap(stka);
	else if (ft_strncmp(op, "sb", 2) == 0)
		op_swap(stkb);
	else if (ft_strncmp(op, "ra", 2) == 0)
		op_rotate(stka);
	else if (ft_strncmp(op, "rba", 2) == 0)
		op_rotate(stkb);
	else if (ft_strncmp(op, "pb", 2) == 0)
		op_push(stkb, stka);
	else if (ft_strncmp(op, "pa", 2) == 0)
		op_push(stka, stkb);
	else if (ft_strncmp(op, "rra", 3) == 0)
		op_rev_rotate(stka);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		op_rev_rotate(stkb);
	else
		return (-1);
	return (1);
}

void	init_stack(char *argv[], t_list **stka)
{
	int		i;

	i = -1;
	while (argv[++i])
		ft_lstadd_back(stka, ft_lstnew(ft_atoi(argv[i]), -1));
	position(stka);
	turn_binary(stka);
}

void	write_ok(t_list *stka)
{
	if (sorted(&stka) != -1)
		write(1, "OK", 2);
	else
		write (1, "KO", 2);
}

int	main(int argc, char *argv[])
{
	char	**nums;
	char	*op;
	t_list	*stka;
	t_list	*stkb;

	nums = parse_input(argv, argc);
	stkb = NULL;
	stka = NULL;
	init_stack(nums, &stka);
	if (check_input(nums) == -1)
		return (0);
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
