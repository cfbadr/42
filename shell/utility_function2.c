/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_function2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 16:18:10 by bchoukri          #+#    #+#             */
/*   Updated: 2015/06/11 15:22:31 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"
#include "libft.h"
#include <stdio.h>

int				previous_folder(t_list *var)
{
	char		*str;
	char		*old_pwd;
	int			pos;

	if ((str = malloc(sizeof(char) * 300)) == NULL)
		return (-1);
	if ((pos = find_pos(var, "OLDPWD")) == -1)
		return (-1);
	str = getcwd(str, 300);
	old_pwd = ft_strsub(var->env[pos], 7, ft_strlen(var->env[pos]));
	make_setenv(var, "OLDPWD", str);
	if ((chdir(old_pwd)) == -1)
		return (-1);
	make_setenv(var, "PWD", old_pwd);
	return (1);
}

int				how_much_need_cute(char *str)
{
	char		**tab;
	int			i;

	i = 0;
	tab = ft_strsplit(str, '/');
	while (tab[i] != NULL)
		i++;
	return (i);
}

char			*cut_the_slash(char *str, char *point)
{
	int			i;
	int			pos;
	char		*new_str;

	i = ft_strlen(str);
	pos = how_much_need_cute(point);
	while (pos > 0)
	{
		while (str[i] != '/' && i > 0)
			i--;
		if (i > 0)
			i--;
		pos--;
	}
	new_str = ft_strsub(str, 0, i);
	return (new_str);
}

void			back_one_step(t_list *var, char *str)
{
	int			pos;
	char		*new_str;

	if ((pos = find_pos(var, "OLDPWD")) == -1)
		return ;
	new_str = ft_strsub(var->env[pos], 7, ft_strlen(var->env[pos]));
	new_str = cut_the_slash(new_str, str);
	var->env = make_setenv(var, "PWD", new_str);
}

int				no_file_or_previous_file(t_list *var, char *str)
{
	char		*oldpwd;

	if ((oldpwd = malloc(sizeof(char) * 300)) == NULL)
		return (-1);
	if (ft_strcmp("-", str) == 0)
	{
		if ((previous_folder(var)) == -1)
			return (-1);
		return (1);
	}
	if (ft_strcmp("..", str) == 0 || ft_strncmp("../", str, 3) == 0)
		back_one_step(var, str);
	oldpwd = getcwd(oldpwd, 300);
	var->env = make_setenv(var, "OLDPWD", oldpwd);
	if (chdir(str) == -1)
	{
		ft_putstr("No such file or directory\n");
		return (-1);
	}
	return (0);
}
