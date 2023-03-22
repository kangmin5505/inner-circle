/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:42:54 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/07 20:54:20 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_info *fmt_info)
{
	int	cnt;

	cnt = 0;
	if (fmt_info->left_align == 1)
	{
		cnt += ft_putchar('%');
		while (fmt_info->width-- > 1)
			cnt += ft_putchar(' ');
	}
	else
	{
		while (fmt_info->width-- > 1)
		{
			if (fmt_info->nbr_zero_sign == 1)
				cnt += ft_putchar('0');
			else
				cnt += ft_putchar(' ');
		}	
		cnt += ft_putchar('%');
	}
	return (cnt);
}
