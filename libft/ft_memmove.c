/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:01:39 by bchoukri          #+#    #+#             */
/*   Updated: 2015/12/29 13:45:35 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *tmp;
	unsigned char *tmp2;

	tmp = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if (dst > src)
	{
		tmp = tmp + n;
		tmp2 = tmp2 + n;
		while (n--)
			*--tmp = *--tmp2;
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
