/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 21:14:58 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/03 22:48:31 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a(t_stack *stack_a, t_stack *stack_b, int left, int right)
{
	int		mid;
	int		size;

	size = right - left + 1;
	if (pre_checker_b(stack_a, stack_b, size) == true)
		return ;
	mid = (left + right + 1) / 2;
	b_to_a_sub(stack_a, stack_b, left, right);
	a_to_b(stack_a, stack_b, left, mid);
	b_to_a(stack_a, stack_b, mid + 1, right);
}

void	move_target_rank(t_stack *stack_a, int mid)
{
	t_node	*curr;
	int		ra_cnt;
	int		rra_cnt;

	curr = stack_a->head->next;
	ra_cnt = 1;
	while (curr->rank <= mid)
	{
		ra_cnt++;
		curr = curr->next;
	}
	curr = stack_a->tail;
	rra_cnt = 1;
	while (curr->rank <= mid)
	{
		rra_cnt++;
		curr = curr->prev;
	}
	if (ra_cnt < rra_cnt)
		while (ra_cnt--)
			rotate(stack_a);
	else
		while (rra_cnt--)
			r_rotate(stack_a);
}

void	a_to_b(t_stack *stack_a, t_stack *stack_b, int left, int right)
{
	int			mid;
	int			ra_cnt;
	static bool	s_flag = false;
	int			size;

	size = right - left + 1;
	if (pre_checker_a(stack_a, stack_b, size, s_flag) == true)
	{
		s_flag = true;
		return ;
	}
	mid = (left + right + 1) / 2;
	ra_cnt = a_to_b_sub(stack_a, stack_b, left, right);
	while (s_flag == true && ra_cnt--)
		r_rotate(stack_a);
	a_to_b(stack_a, stack_b, left, mid - 1);
	b_to_a(stack_a, stack_b, mid, right);
}

void	complex_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	left;
	int	right;

	left = 1;
	right = stack_a->num_of_data;
	a_to_b(stack_a, stack_b, left, right);
}
