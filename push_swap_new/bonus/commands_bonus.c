/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:06:56 by dramos-n          #+#    #+#             */
/*   Updated: 2024/04/18 18:06:57 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_cmd(char *op, t_stack **stka, t_stack **stkb)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		sa(stka, 0);
	else if (ft_strncmp(op, "sb", 2) == 0)
		sb(stkb, 0);
	else if (ft_strncmp(op, "ss", 2) == 0)
		ss(stka, stkb, 0);
}

void	push_cmd(char *op, t_stack **stka, t_stack **stkb)
{
	if (ft_strncmp(op, "pb", 2) == 0)
		pb(stka, stkb, 0);
	else if (ft_strncmp(op, "pa", 2) == 0)
		pa(stka, stkb, 0);
}

void	rotate_cmd(char *op, t_stack **stka, t_stack **stkb)
{
	if (ft_strncmp(op, "ra", 2) == 0)
		ra(stka, 0);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rb(stkb, 0);
	else if (ft_strncmp(op, "rr", 2) == 0)
	{
		if (ft_strncmp(op, "rra", 3) == 0)
			rra(stka, 0);
		else if (ft_strncmp(op, "rrb", 3) == 0)
			rrb(stkb, 0);
		else
			rrr(stka, stkb, 0);
	}
}
