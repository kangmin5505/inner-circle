/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:15:35 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/07 20:53:59 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hash(t_info *fmt_info)
{
	int	cnt;

	cnt = 0;
	if (fmt_info->type == 'x')
		cnt += ft_putstr("0x");
	else if (fmt_info->type == 'X')
		cnt += ft_putstr("0X");
	fmt_info->width -= 2;
	return (cnt);
}

void	str_toupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper((int)*str);
		str++;
	}
}

int	print_unsigned_nbr(unsigned int nbr, t_info *fmt_info)
{
	int		cnt;
	char	type;
	char	*nbr_str;
	int		str_len;

	cnt = 0;
	type = fmt_info->type;
	nbr_str = NULL;
	if (type == 'u')
		nbr_str = ft_uitoa(nbr);
	else if (type == 'x' || type == 'X')
		nbr_str = ft_uitoa_base(nbr, 16);
	if (type == 'X')
		str_toupper(nbr_str);
	if (fmt_info->nbr_hash == 1 && nbr != 0)
		cnt += print_hash(fmt_info);
	str_len = ft_strlen(nbr_str);
	if (fmt_info->left_align == -1)
		cnt += print_str_right_align(nbr_str, str_len, fmt_info);
	else
		cnt += print_str_left_align(nbr_str, str_len, fmt_info);
	free(nbr_str);
	nbr_str = NULL;
	return (cnt);
}

int	print_signed_nbr(int nbr, t_info *fmt_info)
{
	int		cnt;
	char	*nbr_str;
	char	*temp;

	cnt = 0;
	nbr_str = ft_itoa(nbr);
	temp = nbr_str;
	if (nbr < 0 && fmt_info->width > fmt_info->precision \
		&& fmt_info->precision != -1 && fmt_info->left_align == -1)
	{
		while (fmt_info->width > (fmt_info->precision + 1) && \
				fmt_info->width > ft_strlen(nbr_str))
		{
			cnt += ft_putchar(' ');
			fmt_info->width -= 1;
		}
	}
	cnt += print_sign(&nbr_str, fmt_info, nbr);
	if (fmt_info->left_align == -1)
		cnt += print_str_right_align(nbr_str, ft_strlen(nbr_str), fmt_info);
	else
		cnt += print_str_left_align(nbr_str, ft_strlen(nbr_str), fmt_info);
	free(temp);
	temp = NULL;
	return (cnt);
}

int	print_number(va_list *ap, t_info *fmt_info)
{
	int				cnt;
	char			type;
	int				signed_nbr;
	unsigned int	unsigned_nbr;

	cnt = 0;
	type = fmt_info->type;
	if (type == 'd' || type == 'i')
	{
		signed_nbr = va_arg(*ap, int);
		cnt += print_signed_nbr(signed_nbr, fmt_info);
	}
	else if (type == 'u' || type == 'x' || type == 'X')
	{
		unsigned_nbr = va_arg(*ap, unsigned int);
		cnt += print_unsigned_nbr(unsigned_nbr, fmt_info);
	}
	return (cnt);
}
