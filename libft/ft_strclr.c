/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:40:38 by bchoukri          #+#    #+#             */
/*   Updated: 2014/11/15 15:10:16 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strclr(char *s)
{
	int		i;
	int		j;

	i = 0;
	if (s != NULL)
	{
		j = ft_strlen(s);
		while (j > 0)
		{
			s[i] = '\0';
			j--;
			i++;
		}
	}
}
