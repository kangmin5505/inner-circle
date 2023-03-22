/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:32:31 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/03 22:14:56 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_node	*node;
	t_node	*curr;

	curr = (*stack)->head;
	while (curr)
	{
		node = curr;
		curr = curr->next;
		free(node);
	}
	free(*stack);
}

bool	check_sort(t_stack *stack_a, int size)
{
	t_node	*next_node;
	int		curr_rank;

	next_node = stack_a->head->next;
	curr_rank = stack_a->head->rank;
	while (next_node && size--)
	{
		if (curr_rank != next_node->rank + 1)
			return (false);
		curr_rank = next_node->rank;
		next_node = next_node->next;
	}
	return (true);
}

bool	check_reverse_sort(t_stack *stack_b, int size)
{
	t_node	*next_node;
	int		curr_rank;

	next_node = stack_b->head->next;
	curr_rank = stack_b->head->rank;
	while (next_node && size--)
	{
		if (curr_rank != next_node->rank - 1)
			return (false);
		curr_rank = next_node->rank;
		next_node = next_node->next;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		init_stack(&stack_a, STACK_A);
		init_stack(&stack_b, STACK_B);
		if (parse_argvs(argc, argv, stack_a) == false)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		if (check_sort(stack_a, stack_a->num_of_data) == false)
			sort_stack(stack_a, stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
