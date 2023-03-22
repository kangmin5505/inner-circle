/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:14:45 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/06 18:46:50 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_fmt_info(t_info *fmt_info)
{
	fmt_info->left_align = -1;
	fmt_info->nbr_zero_sign = -1;
	fmt_info->nbr_hash = -1;
	fmt_info->nbr_space_sign = -1;
	fmt_info->nbr_plus_sign = -1;
	fmt_info->precision = -1;
	fmt_info->width = 0;
	fmt_info->type = '\0';
}
