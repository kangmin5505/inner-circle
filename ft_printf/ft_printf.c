/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:52:33 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/07 11:42:11 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(va_list *ap, t_info *fmt_info)
{
	char	type;
	int		cnt;

	type = fmt_info->type;
	cnt = 0;
	if (type == 'c' || type == 's')
		cnt = print_character(ap, fmt_info);
	else if (type == 'p')
		cnt = print_pointer(ap, fmt_info);
	else if (type == 'd' || type == 'i' || type == 'u' \
			|| type == 'x' || type == 'X')
		cnt = print_number(ap, fmt_info);
	else if (type == '%')
		cnt = print_percent(fmt_info);
	return (cnt);
}

void	parse_specifier(const char **fmt, t_info *fmt_info)
{
	if (ft_strchr(FLAGS, **fmt) != NULL)
		parse_flags(&(*fmt), fmt_info);
	if (ft_isdigit(**fmt) == 1)
		parse_width(&(*fmt), fmt_info);
	if (**fmt == '.')
		parse_precision(&(*fmt), fmt_info);
	if (ft_strchr(TYPES, **fmt) != NULL)
		parse_types(*fmt, fmt_info);
}

int	parse_fmt(va_list *ap, const char *fmt)
{
	t_info	*fmt_info;
	int		cnt;

	cnt = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			cnt += ft_putchar((int)*fmt);
		else
		{
			fmt++;
			fmt_info = (t_info *)malloc(sizeof(t_info));
			if (fmt_info == NULL)
				return (0);
			init_fmt_info(fmt_info);
			parse_specifier(&fmt, fmt_info);
			cnt += print_arg(ap, fmt_info);
			free(fmt_info);
			fmt_info = NULL;
		}
		fmt++;
	}
	return (cnt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, fmt);
	cnt = parse_fmt(&ap, fmt);
	va_end(ap);
	return (cnt);
}
