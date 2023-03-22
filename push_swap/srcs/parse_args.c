/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:46:24 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/30 19:39:41 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_range_nduplicated(char *str, t_stack *stack_a, int *nbr)
{
	long	num;
	t_node	*curr;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	curr = stack_a->head;
	while (curr)
	{
		if (curr->data == (int)num)
			return (false);
		curr = curr->next;
	}
	*nbr = (int)num;
	return (true);
}

bool	check_digit(char *str)
{
	while (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit((int)*str) == 0)
			return (false);
		str++;
	}
	return (true);
}

void	free_dpstr(char **strs)
{
	int	idx;

	idx = 0;
	while (strs[idx])
	{
		free(strs[idx]);
		idx++;
	}
	free(strs);
}

bool	parse_argvs(int argc, char *argv[], t_stack *stack_a)
{
	char	**strs;
	int		argv_idx;
	int		str_idx;
	int		nbr;

	argv_idx = 0;
	while (++argv_idx < argc)
	{
		strs = ft_split(argv[argv_idx], ' ');
		if (!(*strs))
			return (false);
		str_idx = -1;
		while (strs[++str_idx])
		{
			if (check_digit(strs[str_idx]) == false || \
				check_range_nduplicated(strs[str_idx], stack_a, &nbr) == false)
			{
				free(strs);
				return (false);
			}
			add_stack(stack_a, nbr);
		}
		free_dpstr(strs);
	}
	return (true);
}
