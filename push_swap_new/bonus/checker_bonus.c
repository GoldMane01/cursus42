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
	if (ft_strncmp(op, "s", 1) == 0)
		swap_cmd(op, stka, stkb);
	else if (ft_strncmp(op, "p", 1) == 0)
		push_cmd(op, stka, stkb);
	else if (ft_strncmp(op, "r", 1) == 0)
		rotate_cmd(op, stka, stkb);
	else
		return (-1);
	return (1);
}

void	write_ok(t_stack *stka)
{
	if (sorted(&stka))
		write(1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	operate_all(t_stack **stka, t_stack **stkb)
{
	char	*op;

	op = NULL;
	while (op)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		op = ft_strtrim(op, "\n");
		if (operate(op, stka, stkb) == -1)
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stka;
	t_stack	*stkb;

	stkb = NULL;
	stka = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	init_stack(&stka, argv + 1, 2 == argc);
	if (!operate_all(&stka, &stkb))
		return (1);

	/*t_stack *visual;
	visual = stka;
	while (visual)
	{
		printf("->%d\n", visual->num);
		visual = visual->next;
	}*/

	write_ok(stka);
	return (0);
}
