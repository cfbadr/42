/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 20:31:16 by bchoukri          #+#    #+#             */
/*   Updated: 2015/04/19 04:51:10 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_1.h"
#include <stdio.h>

char					**copy_env(char **env)
{
	int					i;
	char				**cpy_env;

	i = 0;
	while (env[i])
		i++;
	if ((cpy_env = (char **)malloc(sizeof(char *) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (env[i])
	{
		cpy_env[i] = ft_strdup(env[i]);
		i++;
	}
	cpy_env[i] = NULL;
	return (cpy_env);
}

char					**new_line_env(t_list **var, char *str)
{
	int					i;
	char				**cpy_env;

	i = 0;
	while ((*var)->env[i])
		i++;
	if ((cpy_env = (char **)malloc(sizeof(char *) * (i + 2))) == NULL)
		return (NULL);
	i = 0;
	while ((*var)->env[i])
	{
		cpy_env[i] = ft_strdup((*var)->env[i]);
		i++;
	}
	cpy_env[i] = ft_strdup(str);
	i++;
	cpy_env[i] = NULL;
	free_double_tabv2((*var));
	return (cpy_env);
}

char					**erase_line_env(t_list **var, int pos)
{
	int					i;
	char				**cpy_env;
	int					j;
	int					value;

	init(&j, &i);
	while ((*var)->env[i])
		i++;
	value = i;
	if ((cpy_env = (char **)malloc(sizeof(char *) * i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (value--)
	{
		if (i == pos)
		{
			j++;
			pos--;
		}
		else
			cpy_env[i++] = ft_strdup((*var)->env[j++]);
	}
	cpy_env[i] = NULL;
	free_double_tabv2(*var);
	return (cpy_env);
}

void					error(char *command)
{
	ft_putstr("\033[31;01mCommand not found:\033[00m");
	ft_putstr(command);
	ft_putchar('\n');
	exit (0);
}
