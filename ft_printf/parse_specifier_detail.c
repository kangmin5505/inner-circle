/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier_detail.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:35:32 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/07 20:51:59 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char **dp_fmt, t_info *fmt_info)
{
	char	fmt_val;

	while (1)
	{
		fmt_val = **dp_fmt;
		if (fmt_val == '-')
			fmt_info->left_align = 1;
		else if (fmt_val == '0')
			fmt_info->nbr_zero_sign = 1;
		else if (fmt_val == '#')
			fmt_info->nbr_hash = 1;
		else if (fmt_val == ' ')
			fmt_info->nbr_space_sign = 1;
		else if (fmt_val == '+')
			fmt_info->nbr_plus_sign = 1;
		else
			break ;
		(*dp_fmt)++;
	}
}

void	parse_width(const char **dp_fmt, t_info *fmt_info)
{
	while (ft_isdigit((int)**dp_fmt) == 1)
	{
		fmt_info->width = fmt_info->width * 10 + (**dp_fmt - '0');
		(*dp_fmt)++;
	}
}

void	parse_precision(const char **dp_fmt, t_info *fmt_info)
{
	fmt_info->precision = 0;
	(*dp_fmt)++;
	while (**dp_fmt == '0')
	{
		fmt_info->nbr_zero_sign = 0;
		(*dp_fmt)++;
	}
	while (ft_isdigit((int)**dp_fmt) == 1)
	{
		fmt_info->precision = fmt_info->precision * 10 + (**dp_fmt - '0');
		(*dp_fmt)++;
	}
}

void	parse_types(const char *fmt, t_info *fmt_info)
{
	fmt_info->type = *fmt;
}
