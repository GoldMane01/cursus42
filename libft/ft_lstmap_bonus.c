/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:22:21 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/12 15:22:22 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	void	*content;

	head = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		if (!content)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new = ft_lstnew(content);
		if (!new)
		{
			ft_lstclear(&head, del);
			(*del)(content);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
