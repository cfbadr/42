/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 22:08:30 by bchoukri          #+#    #+#             */
/*   Updated: 2015/03/02 17:17:55 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*str;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		i = 0;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str)
		{
			while (i < len)
			{
				str[i] = f(s[i]);
				i++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (NULL);
}
