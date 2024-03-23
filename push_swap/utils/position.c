/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:25:44 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:25:45 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_positions(t_list **stk)
{
	t_list	*node;
	int		i;
	int		median;

	i = 0;
	median = ft_lstsize(*stk) / 2;
	node = *stk;
	while (node)
	{
		node->pos = i;
		if (i <= median)
			node->above_median = true;
		else
			node->above_median = false;
		i++;
		node = node->next;
	}
}
