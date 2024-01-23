/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:35:34 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/11 17:35:36 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Applies the function passed as parameter to the content of
 * each element of the list and frees the nodes.
 * lst is the head of a list.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	//Auxiliary nodes
	t_list	*node;
	t_list	*head;

	head = *lst;
	while (head)
	{
		(*del)(head->content);
		node = head->next;
		free(head);
		head = node;
	}
	*lst = NULL;
}
