/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:23:30 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/09 17:23:31 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int number)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node)
	{
		node->num = number;
		node->next = NULL;
	}
	return (node);
}
