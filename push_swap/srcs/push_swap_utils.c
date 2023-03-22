/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 04:52:18 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/03 17:33:52 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	brute_force_a_sub2(t_stack *stack_a, int a, int b, int c)
{
	if (a < b && b < c)
	{
		swap(stack_a);
		rotate(stack_a);
		swap(stack_a);
		r_rotate(stack_a);
		swap(stack_a);
	}
}

void	brute_force_a_sub1(t_stack *stack_a, int a, int b, int c)
{
	if (a > b && b < c)
	{
		rotate(stack_a);
		swap(stack_a);
		r_rotate(stack_a);
		if (a < c)
			swap(stack_a);
	}
	else if (a < b && b > c)
	{
		swap(stack_a);
		if (a < c)
		{
			rotate(stack_a);
			swap(stack_a);
			r_rotate(stack_a);
		}
	}
	else
		brute_force_a_sub2(stack_a, a, b, c);
}

void	brute_force_a(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->head->rank;
	b = stack_a->head->next->rank;
	c = stack_a->head->next->next->rank;
	brute_force_a_sub1(stack_a, a, b, c);
}

bool	check_remain_b(t_stack *stack_b, int mid, int cnt)
{
	t_node	*curr;

	curr = stack_b->head;
	while (cnt--)
	{
		if (curr->rank <= mid)
			return (false);
		curr = curr->next;
	}
	return (true);
}

bool	check_remain_a(t_stack *stack_a, int mid, int cnt)
{
	t_node	*curr;

	curr = stack_a->head;
	while (cnt--)
	{
		if (curr->rank >= mid)
			return (false);
		curr = curr->next;
	}
	return (true);
}
