/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:37:51 by bchoukri          #+#    #+#             */
/*   Updated: 2014/11/15 14:41:58 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (s1 && s2)
	{
		while ((s1[i] != '\0' || s2[i] != '\0') && n > 0)
		{
			if (s1[i] != s2[i])
				return (0);
			n--;
			i++;
		}
		return (1);
	}
	return (-1);
}