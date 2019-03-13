/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:01:39 by bchoukri          #+#    #+#             */
/*   Updated: 2014/11/12 17:39:05 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*cpy;

	cpy = (char*)malloc(sizeof(char*) * n);
	cpy = ft_strncpy(cpy, s2, n);
	s1 = (void*)ft_strncpy(s1, cpy, n);
	free(cpy);
	return (s1);
}
