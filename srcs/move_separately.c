/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_separately.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:08:12 by vbronov           #+#    #+#             */
/*   Updated: 2025/01/04 20:22:36 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_sep_move(t_stacks *stacks, int stack_id, int node_idx)
{
	int	i;

	i = 0;
	if (node_idx < stacks->size[stack_id] / 2)
	{
		while (i < node_idx)
		{
			rotate(stacks, stack_id, TRUE);
			i++;
		}
	}
	else
	{
		while (i < stacks->size[stack_id] - node_idx)
		{
			reverse_rotate(stacks, stack_id, TRUE);
			i++;
		}
	}
}

void	sep_move_algo(t_stacks *stacks, t_params *params)
{
	apply_sep_move(stacks, B, params->src_idx);
	apply_sep_move(stacks, A, params->target_idx);
	pa(stacks, TRUE);
}
