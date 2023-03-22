/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:21:48 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/06 22:24:19 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(unsigned long nbr, int base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char	*ft_ultoa_base(unsigned long n, int base)
{
	unsigned long		nbr;
	int					len;
	char				*str;

	nbr = n;
	len = ft_int_len(nbr, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = "0123456789abcdef"[nbr % base];
		nbr /= base;
	}
	return (str);
}
