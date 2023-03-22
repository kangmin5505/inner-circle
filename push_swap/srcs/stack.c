/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:09:15 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/30 19:49:52 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack, char stack_name)
{
	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	(*stack)->head = NULL;
	(*stack)->tail = NULL;
	(*stack)->num_of_data = 0;
	(*stack)->stack_name = stack_name;
}

void	init_node(t_node *node, t_node *next, t_node *prev, int nbr)
{
	node->data = nbr;
	node->rank = 1;
	node->next = next;
	node->prev = prev;
}

void	set_rank(t_stack *stack, t_node *node)
{
	t_node	*curr;

	curr = stack->head;
	while (curr)
	{
		if (curr->data < node->data)
			curr->rank += 1;
		else if (curr->data > node->data)
			node->rank += 1;
		curr = curr->next;
	}
}

void	add_stack(t_stack *stack, int nbr)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (stack->head == NULL)
	{
		init_node(node, NULL, NULL, nbr);
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		init_node(node, NULL, stack->tail, nbr);
		set_rank(stack, node);
		stack->tail->next = node;
		stack->tail = node;
	}
	stack->num_of_data += 1;
}
