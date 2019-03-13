/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 10:56:09 by bchoukri          #+#    #+#             */
/*   Updated: 2014/11/15 15:09:53 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	int		i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = size;
	while (*dst && size)
	{
		dst++;
		size--;
	}
	if (!size)
		return (src_len + i);
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len + dst_len);
}
