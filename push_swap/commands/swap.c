/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:08:00 by dramos-n          #+#    #+#             */
/*   Updated: 2024/04/18 18:08:01 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **head)
{
	int	aux;

	if (!*head || !(*head)->next)
		return ;
	aux = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = aux;
}

void	sa(t_stack **a, int show)
{
	swap(a);
	if (show)
		write (1, "sa\n", 3);
}

void	sb(t_stack **b, int show)
{
	swap(b);
	if (show)
		write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int show)
{
	swap(a);
	swap(b);
	if (show)
		write (1, "ss\n", 3);
}
