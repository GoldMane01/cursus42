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

int	find_nl(t_list *node)
{
	int	i;

	i = 0;
	while (node->str[i])
	{
		if (node->str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

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

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node)
	{
		node->str = content;
		node->next = NULL;
	}
	return (node);
}

void	ft_lstadd(t_list **list, char *buffer)
{
	t_list	*last;
	t_list	*new;

	new = ft_lstnew(buffer);
	if (!new)
		return (NULL);
	last = ft_lstlast(*list);
	if (!last)
		*list = new;
	else
		last->next = new;
}
