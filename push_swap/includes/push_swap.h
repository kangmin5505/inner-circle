/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:42:42 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/03 23:13:29 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"

# define STACK_A 'a'
# define STACK_B 'b'

typedef struct s_node	t_node;

struct s_node
{
	int		data;
	int		rank;
	t_node	*next;
	t_node	*prev;
};

typedef struct s_stack	t_stack;
struct s_stack
{
	int		num_of_data;
	t_node	*head;
	t_node	*tail;
	char	stack_name;
};

/* main */
void	free_stack(t_stack **stack);
bool	check_sort(t_stack *stack_a, int size);
bool	check_reverse_sort(t_stack *stack_b, int size);

/* push_swap */
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	selection(t_stack *stack_a, t_stack *stack_b, int size);
void	brute_force(t_stack *stack_a);
void	nearest_rotate(t_stack *stack_a);
void	do_operation(t_stack *stack_a, int ra_cnt, int rra_cnt);

/* push_swap_sub */
void	complex_swap(t_stack *stack_a, t_stack *stack_b);
void	a_to_b(t_stack *stack_a, t_stack *stack_b, int left, \
				int right);
void	move_target_rank(t_stack *stack_a, int mid);
void	b_to_a(t_stack *stack_a, t_stack *stack_b, int left, \
				int right);

/* push_swap_sub2 */
bool	pre_checker_b(t_stack *stack_a, t_stack *stack_b, int size);
bool	pre_checker_a(t_stack *stack_a, t_stack *stack_b, int size, \
						bool s_falg);
void	b_to_a_sub(t_stack *stack_a, t_stack *stack_b, int left, int right);
int		a_to_b_sub(t_stack *stack_a, t_stack *stack_b, int left, int right);

/* push_swap_utils */
bool	check_remain_a(t_stack *stack_a, int mid, int cnt);
bool	check_remain_b(t_stack *stack_b, int mid, int cnt);
void	brute_force_a(t_stack *stack_a);
void	brute_force_a_sub1(t_stack *stack_a, int a, int b, int c);
void	brute_force_a_sub2(t_stack *stack_a, int a, int b, int c);

/* parse_argvs */
bool	parse_argvs(int argc, char *argv[], t_stack *stack_a);
bool	check_digit(char *str);
bool	check_range_nduplicated(char *str, t_stack *stack_a, int *nbr);
void	free_dpstr(char **strs);

/* stack */
void	init_stack(t_stack **stack, char stack_name);
void	init_node(t_node *node, t_node *next, t_node *prev, int nbr);
void	add_stack(t_stack *stack, int nbr);
void	set_rank(t_stack *stack, t_node *node);

/* operators */
void	swap(t_stack *stack);
void	push_to_from(t_stack *to_stack, t_stack *from_stack);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);

#endif
