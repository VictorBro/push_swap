/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr_rrr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:08:41 by vbronov           #+#    #+#             */
/*   Updated: 2025/01/02 13:08:43 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stacks *stacks, int idx, int to_print)
{
	if (stacks->size[idx] > 1)
		stacks->s[idx] = stacks->s[idx]->next;
	if (to_print && idx == A)
		ft_printf("ra\n");
	else if (to_print)
		ft_printf("rb\n");
}

void	rr(t_stacks *stacks, int to_print)
{
	rotate(stacks, A, FALSE);
	rotate(stacks, B, FALSE);
	if (to_print)
		ft_printf("rr\n");
}

void	reverse_rotate(t_stacks *stacks, int idx, int to_print)
{
	if (stacks->size[idx] > 1)
		stacks->s[idx] = stacks->s[idx]->prev;
	if (to_print && idx == A)
		ft_printf("rra\n");
	else if (to_print)
		ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks, int to_print)
{
	reverse_rotate(stacks, A, FALSE);
	reverse_rotate(stacks, B, FALSE);
	if (to_print)
		ft_printf("rrr\n");
}
