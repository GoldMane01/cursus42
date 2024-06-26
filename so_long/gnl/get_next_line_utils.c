/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:01:23 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/19 14:01:25 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Frees all the content of the list and buffer for the next run
void	free_all(t_list **list, t_list *node, char *buffer)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (node->str[0])
		*list = node;
	else
	{
		free(buffer);
		free(node);
	}
}

//Searches a list to find a \\n
int	find_nl(t_list *node)
{
	int	i;

	if (!node)
		return (0);
	while (node)
	{
		i = 0;
		while (node->str[i] && i < BUFFER_SIZE)
		{
			if (node->str[i] == '\n')
				return (1);
			i++;
		}
		node = node->next;
	}
	return (0);
}

/** Returns the length of the string that will be created by
 * iterating each element of the list until it finds a \\n
*/
int	len_nl(t_list *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
				return (len + 1);
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

//Returns the last node of a list
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node)
	{
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (node);
}

//Adds the buffer to the next node of the list
void	ft_lstadd(t_list **list, char *buffer)
{
	t_list	*last;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->str = buffer;
	new->next = NULL;
	last = ft_lstlast(*list);
	if (!last)
		*list = new;
	else
		last->next = new;
}
