/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:09:58 by vbronov           #+#    #+#             */
/*   Updated: 2025/01/04 19:28:47 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	has_duplicates(t_stacks *stacks, int num)
{
	t_node	*node;

	if (stacks->size[A] == 0)
		return (FALSE);
	node = stacks->s[A];
	while (node->next != stacks->s[A])
	{
		if (node->nbr == num)
			return (TRUE);
		node = node->next;
	}
	if (node->nbr == num)
		return (TRUE);
	return (FALSE);
}

int	error_handle(t_stacks *stacks)
{
	free_stacks(stacks);
	ft_printf("Error\n");
	return (FALSE);
}

int	split_args(t_stacks *stacks, char *str)
{
	int		count;
	char	*end;
	int		num;

	count = 0;
	end = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && is_whitespace(*str))
			str++;
		end = str;
		while (*end != '\0' && !is_whitespace(*end))
			end++;
		if (end == str && count == 0)
			return (error_handle(stacks));
		if (end > str)
		{
			if (!get_atoi(str, &num) || !add_to_stack(stacks, num))
				return (error_handle(stacks));
			count++;
		}
		str = end;
	}
	return (TRUE);
}
