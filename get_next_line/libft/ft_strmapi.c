/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 22:26:21 by bchoukri          #+#    #+#             */
/*   Updated: 2014/11/15 22:32:15 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*str;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str)
		{
			while (i < len)
			{
				str[i] = f(i, s[i]);
				i++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (NULL);
}
