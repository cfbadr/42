/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 10:12:37 by bchoukri          #+#    #+#             */
/*   Updated: 2014/11/15 19:35:49 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *s1, char *s2)
{
	int i;
	int pos;
	int len;

	i = 0;
	pos = 0;
	len = 0;
	while (s2[len] != '\0')
		len++;
	if (len == 0)
		return (s1);
	while (s1[i])
	{
		while (s2[pos] == s1[i + pos])
		{
			if (pos == len - 1)
				return (s1 + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
