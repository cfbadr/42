/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins_fonc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 20:00:02 by bchoukri          #+#    #+#             */
/*   Updated: 2015/06/11 16:22:16 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"
#include "libft.h"
#include <stdio.h>

void		make_cd(t_list *var, char **tab_line)
{
	int		pos;
	char	*oldpwd;
	int		i;

	if ((oldpwd = malloc(sizeof(char) * 300)) == NULL)
		return ;
	if (tab_line[1] == NULL)
	{
		if ((i = find_pos(var, "HOME")) == -1)
			return ;
		oldpwd = ft_strsub(var->env[i], 5, ft_strlen(var->env[i]));
		var->env = make_setenv(var, "PWD", oldpwd);
		chdir(oldpwd);
		return ;
	}
	if (no_file_or_previous_file(var, tab_line[1]) != 0)
		return ;
	pos = find_pos(var, "PWD");
	if (pos > 0)
	{
		oldpwd = getcwd(oldpwd, 300);
		var->env = make_setenv(var, "PWD", oldpwd);
	}
}

char		**make_setenv(t_list *var, char *str, char *str2)
{
	int		i;
	int		check;
	char	*new_str;
	int		len;
	int		pos;

	new_str = ft_strjoin(str, "=");
	len = ft_strlen(new_str);
	check = 0;
	i = 0;
	pos = find_pos(var, str);
	new_str = ft_strjoin(new_str, str2);
	if (pos != 1)
		var->env = erase_line_env(&var, pos);
	var->env = new_line_env(&var, new_str);
	return (var->env);
}

char		**make_unsetenv(t_list *var, char *str)
{
	int		pos;

	if ((ft_strcmp(str, "PATH")) == 0)
		return (var->env);
	pos = find_pos(var, str);
	if (pos != 1)
		var->env = erase_line_env(&var, pos);
	return (var->env);
}

void		make_env(t_list *var)
{
	int	i;

	i = 0;
	while (var->env[i])
	{
		ft_putstr(var->env[i]);
		ft_putchar('\n');
		i++;
	}
}

char		**execute_bultins(t_list *var, char **tab_li, int bultins_nb)
{
	if (bultins_nb == 1)
		make_cd(var, tab_li);
	else if (bultins_nb == 2 && tab_li[1] != NULL && tab_li[2] != NULL)
		var->env = make_setenv(var, tab_li[1], tab_li[2]);
	else if (bultins_nb == 3 && tab_li[1] != NULL)
		var->env = make_unsetenv(var, tab_li[1]);
	else if (bultins_nb == 4)
		make_env(var);
	return (var->env);
}
