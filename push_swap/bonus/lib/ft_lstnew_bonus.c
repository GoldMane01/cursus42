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

#include "../checker_bonus.h"

t_list	*ft_lstnew(int number, int position)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node)
	{
		node->num = number;
		node->pos = position;
		node->next = NULL;
	}
	return (node);
}
