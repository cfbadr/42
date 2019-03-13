/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 12:12:33 by bchoukri          #+#    #+#             */
/*   Updated: 2015/12/29 13:58:14 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char *ft_strnstr(const char *str, const char *tofind, size_t n)
{
	unsigned int i;
	unsigned int j;
	unsigned int len;

	if (*tofind == '\0')
		return ((char *)str);
	i = 0;
	len = ft_strlen(tofind);
	while (str[i] && i + len - 1 < n)
	{
		if (str[i] == *tofind)
		{
			j = 0;
			while (str[i + j] == tofind[j] && (i + j) < n)
			{
				if (tofind[1 + j] == '\0' || (i + j) == n - 1)
					return ((char *)str + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
