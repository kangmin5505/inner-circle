/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:19:45 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/07 20:54:40 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list *ap, t_info *fmt_info)
{
	int				cnt;
	unsigned long	nbr;
	char			*str;
	int				str_len;
	char			*temp;

	cnt = 0;
	nbr = va_arg(*ap, unsigned long);
	str = ft_ultoa_base(nbr, 16);
	temp = str;
	str = ft_strjoin("0x", temp);
	str_len = ft_strlen(str);
	if (fmt_info->left_align == -1 && nbr == 0)
		cnt += print_str_right_align("0x0", 3, fmt_info);
	else if (fmt_info->left_align == 1 && nbr == 0)
		cnt += print_str_left_align("0x0", 3, fmt_info);
	else if (fmt_info->left_align == -1)
		cnt += print_str_right_align(str, str_len, fmt_info);
	else if (fmt_info->left_align == 1)
		cnt += print_str_left_align(str, str_len, fmt_info);
	free(str);
	free(temp);
	str = NULL;
	temp = NULL;
	return (cnt);
}
