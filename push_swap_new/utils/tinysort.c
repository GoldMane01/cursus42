/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:09:12 by dramos-n          #+#    #+#             */
/*   Updated: 2024/04/18 18:09:14 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	tiny_sort(t_stack **a)
{
	t_stack	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(a, 1);
	else if ((*a)->next == highest)
		rra(a, 1);
	if ((*a)->num > (*a)->next->num)
		sa(a, 1);
}
