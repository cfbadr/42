/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:16:16 by bchoukri          #+#    #+#             */
/*   Updated: 2015/03/20 06:59:32 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	void		*str;
	size_t		i;

	i = 0;
	if ((str = (char *)malloc(sizeof(char) * (int)size)) == NULL)
		return (NULL);
	while (i < size)
	{
		((char *)str)[size] = '0';
		i++;
	}
	return (str);
}
