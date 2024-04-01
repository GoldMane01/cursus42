/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:25:29 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:25:30 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_list **stk)
{
	t_list	*node;
	t_list	*next;

	node = (*stk);
	next = NULL;
	if (node)
		next = node->next;
	while (next)
	{
		if (node->num > next->num)
			return (-1);
		node = node->next;
		next = node->next;
	}
	return (1);
}

char	**parse_input(char *argv[], int argc)
{
	char	*join;
	char	**nums;
	int		i;

	nums = NULL;
	join = malloc(sizeof(char) * 2);
	if (!join)
		return (NULL);
	join[0] = ' ';
	join[1] = '\0';
	i = 1;
	while (i < argc)
	{
		join = ft_strjoin(join, argv[i]);
		ft_strlcat(join, " ", ft_strlen(join) + ft_strlen(" ") + 1);
		i++;
	}
	nums = ft_split(join, ' ');
	return (nums);
}

void	refresh_nodes(t_list *stka, t_list *stkb)
{
	set_positions(&stka);
	set_positions(&stkb);
	set_target(stka, stkb);
	set_price(stka, stkb);
	set_cheapest(stkb);
}

t_list	*get_cheapest(t_list *stk)
{
	if (!stk)
		return (NULL);
	while (stk)
	{
		if (stk->cheapest)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

t_list	*find_smallest(t_list *stk)
{
	t_list	*node;
	int		smallest;

	smallest = INT_MAX;
	while (stk)
	{
		if (stk->num < smallest)
		{
			smallest = stk->num;
			node = stk;
		}
		stk = stk->next;
	}
	return (node);
}