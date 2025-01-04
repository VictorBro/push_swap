/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:07:58 by vbronov           #+#    #+#             */
/*   Updated: 2025/01/04 19:28:47 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	t_node	*node;

	ft_printf("Stack A:\n");
	node = stacks->s[A];
	while (node)
	{
		ft_printf("%d\n", node->nbr);
		node = node->next;
		if (node == stacks->s[A])
			break ;
	}
	ft_printf("Stack B:\n");
	node = stacks->s[B];
	while (node)
	{
		ft_printf("%d\n", node->nbr);
		node = node->next;
		if (node == stacks->s[B])
			break ;
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	init_stacks(&stacks);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (error_handle(&stacks));
		if (!split_args(&stacks, argv[i]))
			return (0);
		i++;
	}
	push_swap(&stacks);
	free_stacks(&stacks);
	return (0);
}
