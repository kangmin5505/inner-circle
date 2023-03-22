/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:33:27 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/03 12:24:41 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp_data;
	int	temp_rank;

	if (stack->num_of_data <= 1)
		return ;
	temp_data = stack->head->data;
	temp_rank = stack->head->rank;
	stack->head->data = stack->head->next->data;
	stack->head->rank = stack->head->next->rank;
	stack->head->next->data = temp_data;
	stack->head->next->rank = temp_rank;
	ft_putchar_fd('s', STDOUT_FILENO);
	ft_putchar_fd(stack->stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	push_to_from(t_stack *to_stack, t_stack *from_stack)
{
	t_node	*temp_node;

	if (from_stack->num_of_data == 0)
		return ;
	temp_node = from_stack->head;
	from_stack->head = from_stack->head->next;
	if (from_stack->num_of_data == 1)
		from_stack->tail = NULL;
	temp_node->next = to_stack->head;
	temp_node->prev = NULL;
	if (to_stack->num_of_data == 0)
	{
		to_stack->head = temp_node;
		to_stack->tail = temp_node;
	}
	else
	{
		to_stack->head->prev = temp_node;
		to_stack->head = temp_node;
	}
	to_stack->num_of_data += 1;
	from_stack->num_of_data -= 1;
	ft_putchar_fd('p', STDOUT_FILENO);
	ft_putchar_fd(to_stack->stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	rotate(t_stack *stack)
{
	t_node	*temp_node;

	if (stack->num_of_data <= 1)
		return ;
	temp_node = stack->head;
	stack->head = temp_node->next;
	temp_node->next->prev = NULL;
	temp_node->next = NULL;
	temp_node->prev = stack->tail;
	temp_node->prev->next = temp_node;
	stack->tail = temp_node;
	ft_putchar_fd('r', STDOUT_FILENO);
	ft_putchar_fd(stack->stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	r_rotate(t_stack *stack)
{
	t_node	*temp_node;

	if (stack->num_of_data <= 1)
		return ;
	temp_node = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	temp_node->next = stack->head;
	temp_node->prev = NULL;
	temp_node->next->prev = temp_node;
	stack->head = temp_node;
	ft_putstr_fd("rr", STDOUT_FILENO);
	ft_putchar_fd(stack->stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
