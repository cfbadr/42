/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:51:18 by bchoukri          #+#    #+#             */
/*   Updated: 2015/01/02 22:39:16 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s2[i] == '\0')
			return (1);
		if (s1[i] != s2[i])
			return ((s1[i] > s2[i]) ? 1 : -1);
		i++;
	}
	if (s2[i] != '\0' && i != n)
		return (-1);
	return (0);
}