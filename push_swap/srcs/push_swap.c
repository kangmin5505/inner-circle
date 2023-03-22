/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:46:23 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/03 22:00:16 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	brute_force(t_stack *stack_a)
{
	while (check_sort(stack_a, stack_a->num_of_data) == false)
	{
		if (stack_a->head->data < stack_a->tail->data)
			swap(stack_a);
		else if (stack_a->head->data > stack_a->head->next->data)
			rotate(stack_a);
		else
			r_rotate(stack_a);
	}
}

void	do_operation(t_stack *stack_a, int ra_cnt, int rra_cnt)
{
	if (ra_cnt < rra_cnt)
		while (ra_cnt--)
			rotate(stack_a);
	else
		while (rra_cnt--)
			r_rotate(stack_a);
}

void	nearest_rotate(t_stack *stack_a)
{
	t_node	*curr;
	int		ra_cnt;
	int		rra_cnt;

	curr = stack_a->head->next;
	ra_cnt = 1;
	while (curr)
	{
		if (curr->rank > 3)
			break ;
		ra_cnt++;
		curr = curr->next;
	}
	curr = stack_a->tail;
	rra_cnt = 1;
	while (curr)
	{
		if (curr->rank > 3)
			break ;
		rra_cnt++;
		curr = curr->prev;
	}
	do_operation(stack_a, ra_cnt, rra_cnt);
}

void	selection(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_node	*curr;

	while (stack_a->num_of_data > 3)
	{
		curr = stack_a->head;
		if (curr->rank > 3)
			push_to_from(stack_b, stack_a);
		else
			nearest_rotate(stack_a);
	}
	brute_force(stack_a);
	if (size == 5)
		if (stack_b->head->rank > stack_b->head->next->rank)
			swap(stack_b);
	while (size-- > 3)
		push_to_from(stack_a, stack_b);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->num_of_data == 2)
		swap(stack_a);
	else if (stack_a->num_of_data == 3)
		brute_force(stack_a);
	else if (stack_a->num_of_data <= 5)
		selection(stack_a, stack_b, stack_a->num_of_data);
	else
		complex_swap(stack_a, stack_b);
}
