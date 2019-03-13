/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:56:32 by bchoukri          #+#    #+#             */
/*   Updated: 2014/11/13 17:12:44 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0' && n > 0)
	{
		s1[len] = s2[i];
		i++;
		len++;
		n--;
	}
	s1[len] = '\0';
	return (s1);
}
