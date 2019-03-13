/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:39:15 by bchoukri          #+#    #+#             */
/*   Updated: 2015/12/29 13:43:43 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char i;

	if (n != 0)
	{
		ptr = (unsigned char*)s;
		i = 0;
		while (i < n)
		{
			if ((unsigned char)c == ptr[i])
				return ((void*)(ptr + i));
			i++;
		}
	}
	return (NULL);
}
