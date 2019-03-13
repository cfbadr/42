/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:33:19 by bchoukri          #+#    #+#             */
/*   Updated: 2015/01/03 17:35:46 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnew(size_t size)
{
	char		*str;

	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (size > 0)
	{
		str[size] = '\0';
		size--;
	}
	return (str);
}
