/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:05:53 by vbronov           #+#    #+#             */
/*   Updated: 2025/01/04 20:32:38 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_separate_price(t_stacks *stacks, int src_idx, int target_idx)
{
	int	price;

	if (src_idx < stacks->size[B] / 2)
		price = src_idx;
	else
		price = stacks->size[B] - src_idx;
	if (target_idx < stacks->size[A] / 2)
		price += target_idx;
	else
		price += stacks->size[A] - target_idx;
	return (price);
}

static int	calc_price_rr(int src_idx, int target_idx)
{
	int	price;

	if (src_idx <= target_idx)
	{
		price = src_idx;
		price += target_idx - src_idx;
	}
	else
	{
		price = target_idx;
		price += src_idx - target_idx;
	}
	return (price);
}

static int	calc_price_rrr(t_stacks *stacks, int src_idx, int target_idx)
{
	int	price;

	if (stacks->size[B] - src_idx <= stacks->size[A] - target_idx)
	{
		price = stacks->size[B] - src_idx;
		price += stacks->size[A] - target_idx - price;
	}
	else
	{
		price = stacks->size[A] - target_idx;
		price += stacks->size[B] - src_idx - price;
	}
	return (price);
}

void	calc_price(t_stacks *stacks, t_node *node, t_params *params)
{
	int	tmp_price;

	params->target_idx = get_target_idx(stacks, node->nbr);
	params->algorithm = SEPARATED;
	params->price = calc_separate_price(stacks,
			params->src_idx, params->target_idx);
	tmp_price = calc_price_rr(params->src_idx, params->target_idx);
	if (tmp_price < params->price)
	{
		params->price = tmp_price;
		params->algorithm = RR;
	}
	tmp_price = calc_price_rrr(stacks, params->src_idx, params->target_idx);
	if (tmp_price < params->price)
	{
		params->price = tmp_price;
		params->algorithm = RRR;
	}
}
