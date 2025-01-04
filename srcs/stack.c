/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:09:26 by vbronov           #+#    #+#             */
/*   Updated: 2025/01/02 13:09:28 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stacks *stacks)
{
	stacks->s[A] = NULL;
	stacks->s[B] = NULL;
	stacks->size[A] = 0;
	stacks->size[B] = 0;
}

void	free_stacks(t_stacks *stacks)
{
	t_node	*node;

	node = pop(stacks, A);
	while (node)
	{
		free(node);
		node = pop(stacks, A);
	}
	node = pop(stacks, B);
	while (node)
	{
		free(node);
		node = pop(stacks, B);
	}
}

t_node	*pop(t_stacks *stacks, int idx)
{
	t_node	*node;

	if (stacks->size[idx] == 0)
		return (NULL);
	node = stacks->s[idx];
	if (stacks->size[idx] == 1)
		stacks->s[idx] = NULL;
	else
	{
		stacks->s[idx] = node->next;
		stacks->s[idx]->prev = node->prev;
		node->prev->next = stacks->s[idx];
	}
	stacks->size[idx]--;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push(t_stacks *stacks, t_node *node, int idx)
{
	if (stacks->size[idx] == 0)
	{
		stacks->s[idx] = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = stacks->s[idx];
		node->prev = stacks->s[idx]->prev;
		stacks->s[idx]->prev->next = node;
		stacks->s[idx]->prev = node;
		stacks->s[idx] = node;
	}
	stacks->size[idx]++;
}

int	add_to_stack(t_stacks *stacks, int num)
{
	t_node	*node;

	if (has_duplicates(stacks, num))
		return (FALSE);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (FALSE);
	node->nbr = num;
	node->next = NULL;
	node->prev = NULL;
	push(stacks, node, A);
	rotate(stacks, A, FALSE);
	return (TRUE);
}
