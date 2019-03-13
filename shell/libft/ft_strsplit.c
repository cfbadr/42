/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 18:02:23 by bchoukri          #+#    #+#             */
/*   Updated: 2015/04/19 01:34:46 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int words;

	words = 0;
	while (*s)
	{
		if (c != *s && *s)
		{
			++words;
			while (c != *s && *s)
				++s;
		}
		else
			++s;
	}
	return (words);
}

static void	make_split(char const *s, char c, char ***result)
{
	int j;
	int i;

	i = 0;
	while (*s)
	{
		while ((c == *s || *s == '\t') && *s)
			++s;
		j = 0;
		while (c != *(s + j) && *(s + j))
			++j;
		if (j)
		{
			(*result)[i] = malloc(sizeof(char) * (j + 1));
			if (!(*result)[i])
				return ;
			j = 0;
			while (c != *s && *s)
				(*result)[i][j++] = *s++;
			(*result)[i++][j] = '\0';
		}
	}
	(*result)[i] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	make_split(s, c, &result);
	return (result);
}
