/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:26:02 by bchoukri          #+#    #+#             */
/*   Updated: 2015/02/03 11:02:27 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank_custom(int c)
{
	return ((c == ' ' || c == '\t' || c == '\n') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	len = 0;
	str = ft_strnew(ft_strlen(s));
	while (len < ft_strlen(s))
	{
		if (!i && ft_isblank_custom(s[len]))
			len++;
		else
			str[i++] = s[len++];
	}
	while (ft_isblank_custom(str[--i]))
		str[i] = '\0';
	return (str);
}
