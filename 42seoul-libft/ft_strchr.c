/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:29:23 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/02 16:00:42 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;
	char	*ret;

	find = (char)c;
	ret = (char *)s;
	while (*ret)
	{
		if (*ret == find)
			return (ret);
		ret++;
	}
	if (*ret == find)
		return (ret);
	return (NULL);
}
