/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:16:16 by bchoukri          #+#    #+#             */
/*   Updated: 2015/12/29 13:59:05 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *str;

	if (!size)
		return (NULL);
	str = (void *)malloc(size);
	if (!str)
		return (NULL);
	ft_bzero((void *)str, size);
	return ((void *)str);
}

