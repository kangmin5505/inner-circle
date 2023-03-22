/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:20:45 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/23 12:52:25 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sign(char **nbr_str, t_info *fmt_info, int nbr)
{
	int	cnt;

	cnt = 0;
	if ((fmt_info->nbr_plus_sign == 1 || fmt_info->nbr_space_sign == 1) \
		&& nbr >= 0 && fmt_info->type != 'u')
	{
		if (fmt_info->nbr_plus_sign == 1)
			cnt += ft_putchar('+');
		else if (fmt_info->nbr_space_sign == 1)
			cnt += ft_putchar(' ');
		fmt_info->width -= 1;
	}
	else if (nbr < 0 && fmt_info->type != 'u')
	{
		if ((fmt_info->precision >= ft_strlen(*nbr_str) || \
			fmt_info->precision >= fmt_info->width) || \
			(fmt_info->nbr_zero_sign == 1))
		{
			cnt += ft_putchar((int)(**nbr_str));
			(*nbr_str)++;
			fmt_info->width -= 1;
		}
	}
	return (cnt);
}

int	print_str_spacenzero(t_info *fmt_info, int str_len, char *str)
{
	int	cnt;
	int	prec;

	cnt = 0;
	prec = fmt_info->precision;
	if (ft_strchr(NUMTYPES, fmt_info->type) != NULL && prec > str_len)
	{
		while (prec-- > str_len)
			cnt += ft_putchar('0');
		cnt += ft_putstr(str);
		while (fmt_info->width - cnt > 0)
			cnt += ft_putchar(' ');
	}
	else
	{
		if (!((str[0] == '0' || fmt_info->type == 's') && prec == 0))
			cnt += ft_putstr(str);
		else if (fmt_info->width != 0)
			cnt += ft_putchar(' ');
		while (fmt_info->width-- > str_len)
			cnt += ft_putchar(' ');
	}
	return (cnt);
}

int	print_spaceozero_str(t_info *fmt_info, int str_len, char *str)
{
	int	cnt;
	int	width;

	cnt = 0;
	width = fmt_info->width;
	if (fmt_info->precision == -1 && fmt_info->nbr_zero_sign == 1)
		while (width - cnt > str_len)
			cnt += ft_putchar('0');
	else if (fmt_info->nbr_zero_sign == 1)
	{
		while (width - cnt > fmt_info->precision && width - cnt - str_len > 0)
			cnt += ft_putchar(' ');
		while (width - cnt > str_len || fmt_info->precision - cnt > str_len)
			cnt += ft_putchar('0');
	}
	else if (ft_strchr(NUMTYPES, fmt_info->type) != NULL && \
			fmt_info->precision > str_len)
		while (fmt_info->precision - cnt > str_len)
			cnt += ft_putchar('0');
	else
		while (width - cnt > str_len)
			cnt += ft_putchar(' ');
	if (!(str[0] == '0' && fmt_info->precision == 0))
		cnt += ft_putstr(str);
	return (cnt);
}

int	print_str_left_align(char *str, int str_len, t_info *fmt_info)
{
	int	cnt;

	cnt = 0;
	if (fmt_info->precision < 1)
	{
		if (str_len >= fmt_info->width && fmt_info->precision != 0)
			cnt += ft_putstr(str);
		else
			cnt += print_str_spacenzero(fmt_info, str_len, str);
	}
	else
	{
		if (fmt_info->precision >= str_len \
			|| ft_strchr(NUMTYPES, fmt_info->type) != NULL)
			cnt += print_str_spacenzero(fmt_info, str_len, str);
		else
		{
			str_len = fmt_info->precision;
			while (str_len--)
				cnt += ft_putchar((int)*str++);
			while (fmt_info->width-- > fmt_info->precision)
				cnt += ft_putchar(' ');
		}
	}
	return (cnt);
}

int	print_str_right_align(char *str, int str_len, t_info *fmt_info)
{
	int		cnt;

	cnt = 0;
	if (fmt_info->precision == -1 && str_len >= fmt_info->width)
		cnt += ft_putstr(str);
	else if (fmt_info->precision == -1)
		cnt += print_spaceozero_str(fmt_info, str_len, str);
	else
	{
		if (fmt_info->precision >= str_len)
			cnt += print_spaceozero_str(fmt_info, str_len, str);
		else if (ft_strchr(NUMTYPES, (int)fmt_info->type) != NULL \
			&& !(str[0] == '0' && fmt_info->precision == 0))
			cnt += print_spaceozero_str(fmt_info, str_len, str);
		else
		{
			while (fmt_info->width-- > fmt_info->precision)
				cnt += ft_putchar(' ');
			while (fmt_info->precision--)
				cnt += ft_putchar((int)*str++);
		}
	}
	return (cnt);
}
