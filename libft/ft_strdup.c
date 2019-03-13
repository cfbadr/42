/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:33:01 by bchoukri          #+#    #+#             */
/*   Updated: 2014/11/13 19:07:53 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*str;

	if ((str = malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	str = ft_strcpy(str, s);
	return (str);
}
