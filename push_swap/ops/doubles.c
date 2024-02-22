/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:25:17 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:25:18 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_ss(t_list **stka, t_list **stkb)
{
	op_swap(stka, 'a');
	op_swap(stkb, 'b');
}

void	op_rr(t_list **stka, t_list **stkb)
{
	op_rotate(stka, 'a');
	op_rotate(stkb, 'b');
}

void	op_rrr(t_list **stka, t_list **stkb)
{
	op_rev_rotate(stka, 'a');
	op_rev_rotate(stkb, 'b');
}
