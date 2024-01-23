/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:55:59 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/11 16:56:00 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Adds a new node to the end of a linked list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	//Auxiliary node to point at the end
	t_list	*node;

	//If the list is NULL, then the new node will be added as the first element
	if (!*lst)
		*lst = new;
	else
	{
		node = ft_lstlast(*lst);
		node->next = new;
	}
}
