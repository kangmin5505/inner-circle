/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sub2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:35:17 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/03 22:49:49 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_to_b_sub(t_stack *stack_a, t_stack *stack_b, int left, int right)
{
	int	mid;
	int	size;
	int	pb_cnt;
	int	ra_cnt;

	mid = (left + right + 1) / 2;
	size = right - left + 1;
	pb_cnt = 0;
	ra_cnt = 0;
	while (check_remain_a(stack_a, mid, size - pb_cnt) == false)
	{
		if (stack_a->head->rank < mid)
		{
			rotate(stack_a);
			ra_cnt++;
		}
		else
		{
			push_to_from(stack_b, stack_a);
			pb_cnt++;
		}
	}
	return (ra_cnt);
}

void	b_to_a_sub(t_stack *stack_a, t_stack *stack_b, int left, int right)
{
	int		rb_cnt;
	int		pa_cnt;
	int		mid;
	int		size;

	rb_cnt = 0;
	pa_cnt = 0;
	size = right - left + 1;
	mid = (left + right + 1) / 2;
	while (check_remain_b(stack_b, mid, size - pa_cnt) == false)
	{
		if (stack_b->head->rank > mid)
		{
			rotate(stack_b);
			rb_cnt++;
		}
		else
		{
			push_to_from(stack_a, stack_b);
			pa_cnt++;
		}
	}
	while (right != stack_a->num_of_data + stack_b->num_of_data && rb_cnt--)
		r_rotate(stack_b);
}

bool	pre_checker_a(t_stack *stack_a, t_stack *stack_b, int size, bool s_flag)
{
	if (size == 0 || size == 1 || check_sort(stack_a, size) == true)
		return (true);
	else if (size == 2)
	{
		swap(stack_a);
		return (true);
	}
	else if (s_flag == true && size == 3)
	{
		brute_force_a(stack_a);
		return (true);
	}
	else if (size <= 5 && size == stack_a->num_of_data)
	{
		selection(stack_a, stack_b, size);
		return (true);
	}
	return (false);
}

bool	pre_checker_b(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (check_reverse_sort(stack_b, size) == true)
	{
		while (size--)
			push_to_from(stack_a, stack_b);
		return (true);
	}
	else if (size == 0)
		return (true);
	else if (size == 1)
	{
		push_to_from(stack_a, stack_b);
		return (true);
	}
	else if (size == 2)
	{
		if (stack_b->head->rank > stack_b->head->next->rank)
			swap(stack_b);
		push_to_from(stack_a, stack_b);
		push_to_from(stack_a, stack_b);
		return (true);
	}
	return (false);
}
