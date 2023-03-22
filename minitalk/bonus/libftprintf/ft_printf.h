/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:55:25 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/08 10:06:25 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FLAGS "-0# +"
# define TYPES "cspdiuxX%"
# define NUMTYPES "pdiuxX"

typedef struct s_info
{
	int		left_align;
	int		nbr_zero_sign;
	int		nbr_hash;
	int		nbr_space_sign;
	int		nbr_plus_sign;
	int		precision;
	int		width;
	char	type;
}	t_info;

/* ft_printf function */
int		ft_printf(const char *fmt, ...);
int		parse_fmt(va_list *ap, const char *fmt);
void	parse_specifier(const char **fmt, t_info *fmt_info);
int		print_arg(va_list *ap, t_info *fmt_info);

/* parse_specifier_detail function */
void	parse_flags(const char **_dp_fmt, t_info *fmt_info);
void	parse_width(const char **dp_fmt, t_info *fmt_info);
void	parse_precision(const char **dp_fmt, t_info *fmt_info);
void	parse_types(const char *fmt, t_info *fmt_info);
int		print_arg(va_list *ap, t_info *fmt_info);

/* print_character function */
int		print_character(va_list *ap, t_info *fmt_info);
int		print_c(char c, t_info *fmt_info);
int		print_null_str(t_info *fmt_info);

/* print_pointer function */
int		print_pointer(va_list *ap, t_info *fmt_info);

/* print_number function */
int		print_number(va_list *ap, t_info *fmt_info);
int		print_signed_nbr(int nbr, t_info *fmt_info);
int		print_unsigned_nbr(unsigned int nbr, t_info *fmt_info);
void	str_toupper(char *str);
int		print_hash(t_info *fmt_info);

/* print_percent function */
int		print_percent(t_info *fmt_info);

/* utils function */
int		print_str_left_align(char *str, int str_len, t_info *fmt_info);
int		print_str_right_align(char *str, int str_len, t_info *fmt_info);
int		print_spaceozero_str(t_info *fmt_info, int str_len, char *str);
int		print_str_spaceozero(t_info *fmt_info, int str_len, char *str);
int		print_sign(char **nbr_str, t_info *fmt_info, int nbr);

/* libft function */
int		ft_putchar(int c);
int		ft_putstr(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
int		ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_uitoa_base(unsigned int n, int base);
char	*ft_ultoa_base(unsigned long n, int base);
char	ft_toupper(int c);
char	*ft_strjoin(char const *s1, char const *s2);

/* fmt_info function */
void	init_fmt_info(t_info *fmt_info);

#endif
