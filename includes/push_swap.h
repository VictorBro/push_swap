/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronov <vbronov@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:04:56 by vbronov           #+#    #+#             */
/*   Updated: 2025/01/04 21:13:50 by vbronov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define FALSE 0
# define TRUE 1
# define A 0
# define B 1

enum e_algorithm
{
	SEPARATED,
	RR,
	RRR,
	RA,
	RB,
	RRA,
	RRB,
	PA,
	PB
};

typedef struct s_node
{
	struct s_node		*next;
	struct s_node		*prev;
	int					nbr;
}				t_node;	

typedef struct s_params
{
	int	src_idx;
	int	target_idx;
	int	price;
	int	algorithm;
}			t_params;

typedef struct s_stacks
{
	t_node			*s[2];
	int				size[2];
}					t_stacks;

void	init_stacks(t_stacks *stacks);
void	free_stacks(t_stacks *stacks);
int		is_whitespace(char c);
int		get_atoi(char *str, int *num);
int		has_duplicates(t_stacks *stacks, int num);
int		add_to_stack(t_stacks *stacks, int num);
int		split_args(t_stacks *stacks, char *str);
t_node	*pop(t_stacks *stacks, int idx);
void	push(t_stacks *stacks, t_node *node, int idx);
void	rotate(t_stacks *stacks, int idx, int to_print);
void	reverse_rotate(t_stacks *stacks, int idx, int to_print);
void	swap(t_stacks *stacks, int idx, int to_print);
void	ss(t_stacks *stacks, int to_print);
void	rr(t_stacks *stacks, int to_print);
void	rrr(t_stacks *stacks, int to_print);
void	pa(t_stacks *stacks, int to_print);
void	pb(t_stacks *stacks, int to_print);
void	push_swap(t_stacks *stacks);
int		is_sorted(t_stacks *stacks);
int		error_handle(t_stacks *stacks);
void	calc_price(t_stacks *stacks, t_node *node, t_params *params);
int		get_target_idx(t_stacks *stacks, int nbr);
int		find_min_idx(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	finalize_pos(t_stacks *stacks);
void	apply_sep_move(t_stacks *stacks, int stack_id, int node_idx);
void	sep_move_algo(t_stacks *stacks, t_params *params);
void	rrr_move_algo(t_stacks *stacks, t_params *params);
void	rr_move_algo(t_stacks *stacks, t_params *params);
#endif