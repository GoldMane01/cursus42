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

void	set_pos(t_list **stka, int max, int position)
{
	t_list	*node;

	node = (*stka);
	while (node)
	{
		if ((node->num == max) && (node->pos == -1))
		{
			node->pos = position;
			return ;
		}
		node = node->next;
	}
}

int	search_max(t_list **stka)
{
	int		max;
	t_list	*node;

	node = (*stka);
	while (node && node->pos != -1)
		node = node->next;
	max = node->num;
	while (node)
	{
		if (node->pos != -1)
			node = node->next;
		else
		{
			if (node->num > max)
				max = node->num;
			node = node->next;
		}
	}
	return (max);
}

void	position(t_list **stka)
{
	int	i;
	int	max_pos;

	i = ft_lstsize((*stka)) - 1;
	while (i >= 0)
	{
		max_pos = search_max(stka);
		set_pos(stka, max_pos, i);
		i--;
	}
}

int	bin_base(int nb)
{
	int	binary;
	int	power;

	power = 1;
	binary = 0;
	while (nb > 0)
	{
		binary += power * (nb % 2);
		power = power * 10;
		nb = nb / 2;
	}
	return (binary);
}

void	turn_binary(t_list **stka)
{
	t_list	*node;

	node = (*stka);
	while (node)
	{
		node->pos = bin_base(node->pos);
		node = node->next;
	}
}
