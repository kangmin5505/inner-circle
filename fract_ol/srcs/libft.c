/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:33:03 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/11 11:15:15 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				idx;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	idx = 0;
	while (ptr1[idx] && ptr2[idx])
	{
		if (ptr1[idx] != ptr2[idx])
			return ((int)(ptr1[idx] - ptr2[idx]));
		idx++;
	}
	if (ptr1[idx] != ptr2[idx])
		return ((int)(ptr1[idx] - ptr2[idx]));
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	idx;

	src_len = ft_strlen(src);
	idx = 0;
	if (!dest && !src)
		return (0);
	if (size == 0)
		return (src_len);
	while (idx < src_len && idx + 1 < size)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (src_len);
}

size_t	ft_strlen(const char *s)
{
	const char	*a;

	if (s == NULL)
		return (0);
	a = s;
	while (*a)
		a++;
	return ((size_t)(a - s));
}
