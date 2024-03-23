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
}

void	rotate_both(t_list **stka, t_list **stkb, t_list *cheap)
{
	while (*stka != cheap->target && *stkb != cheap)
		op_rr(stka, stkb);
	set_positions(stka);
	set_positions(stkb);
}

void	reverse_rotate_both(t_list **stka, t_list **stkb, t_list *cheap)
{
	while (*stka != cheap->target && *stkb != cheap)
		op_rrr(stka, stkb);
	set_positions(stka);
	set_positions(stkb);
}

void	finish_rotation(t_list **stk, t_list *top, char stk_char)
{
	while (*stk != top)
	{
		if (top->above_median)
			op_rotate(stk, stk_char, 1);
		else
			op_rev_rotate(stk, stk_char, 1);
	}
}

void	move_nodes(t_list **stka, t_list **stkb)
{
	t_list	*cheap;

	cheap = get_cheapest(*stkb);
	if (cheap->above_median && cheap->target->above_median)
		rotate_both(stka, stkb, cheap);
	else if (!(cheap->above_median) && !(cheap->target->above_median))
		reverse_rotate_both(stka, stkb, cheap);
	finish_rotation(stkb, cheap, 'b');
	finish_rotation(stka, cheap->target, 'a');
	op_push(stka, stkb, 'a', 1);
	
}