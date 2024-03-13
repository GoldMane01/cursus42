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

#include "../checker_bonus.h"

void	free_all(t_gnl **list, t_gnl *node, char *buffer)
{
	t_gnl	*tmp;

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

int	find_nl(t_gnl *node)
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

int	len_nl(t_gnl *list)
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

t_gnl	*ft_lstlast_gnl(t_gnl *lst)
{
	t_gnl	*node;

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

void	ft_lstadd_gnl(t_gnl **list, char *buffer)
{
	t_gnl	*last;
	t_gnl	*new;

	new = malloc(sizeof(t_gnl));
	if (!new)
		return ;
	new->str = buffer;
	new->next = NULL;
	last = ft_lstlast_gnl(*list);
	if (!last)
		*list = new;
	else
		last->next = new;
}
