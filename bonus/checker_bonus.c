/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:10:27 by vbronov           #+#    #+#             */
/*   Updated: 2025/01/04 21:14:56 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_command(t_stacks *stacks, char *line)
{
	if (!ft_strncmp("rr\n", line, sizeof("rr\n")))
		rr(stacks, FALSE);
	else if (!ft_strncmp("rrr\n", line, sizeof("rrr\n")))
		rrr(stacks, FALSE);
	else if (!ft_strncmp("ra\n", line, sizeof("ra\n")))
		rotate(stacks, A, FALSE);
	else if (!ft_strncmp("rb\n", line, sizeof("rb\n")))
		rotate(stacks, B, FALSE);
	else if (!ft_strncmp("rra\n", line, sizeof("rra\n")))
		reverse_rotate(stacks, A, FALSE);
	else if (!ft_strncmp("rrb\n", line, sizeof("rrb\n")))
		reverse_rotate(stacks, B, FALSE);
	else if (!ft_strncmp("sa\n", line, sizeof("sa\n")))
		swap(stacks, A, FALSE);
	else if (!ft_strncmp("sb\n", line, sizeof("sb\n")))
		swap(stacks, B, FALSE);
	else if (!ft_strncmp("pa\n", line, sizeof("pa\n")))
		pa(stacks, FALSE);
	else if (!ft_strncmp("pb\n", line, sizeof("pb\n")))
		pb(stacks, FALSE);
	else if (!ft_strncmp("ss\n", line, sizeof("ss\n")))
		ss(stacks, FALSE);
	else
		return (FALSE);
	return (TRUE);
}

int	ft_search_command(t_stacks *stacks, char *line)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (line_len < 3 || line_len > 4)
		return (FALSE);
	if (*line == 'r' || *line == 's' || *line == 'p')
		return (ft_do_command(stacks, line));
	return (FALSE);
}

void	ft_apply_commands(t_stacks *stacks)
{
	char	*line;

	while (TRUE)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!ft_search_command(stacks, line))
		{
			ft_printf("Error\n");
			free(line);
			return ;
		}
		free(line);
	}
	if (stacks->size[B] == 0 && is_sorted(stacks))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
	ft_apply_commands(&stacks);
	free_stacks(&stacks);
	return (0);
}
