/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:49:10 by bchoukri          #+#    #+#             */
/*   Updated: 2015/12/29 14:49:15 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;

	while (*s == '\t' || *s == ' ' || *s == '\n')
		s++;
	if (!*s)
		return ("");
	i = ft_strlen(s) - 1;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i--;
	i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
		str[i] = s[i];
	return (str);
}
