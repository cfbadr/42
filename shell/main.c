/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 07:12:29 by bchoukri          #+#    #+#             */
/*   Updated: 2015/06/11 17:37:20 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_1.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>

int		looking_for_path(t_list *var, char ***tab_path, char *line)
{
	int				i;
	char			*line_env;
	unsigned int	y;

	i = 0;
	y = 0;
	if (ft_strlen(line) == 0)
		return (-1);
	while (line[y] != '\0' && line[y] == ' ')
		y++;
	if (y == ft_strlen(line))
		return (-1);
	while (var->env)
	{
		if (ft_strncmp("PATH=", var->env[i], 5) == 0)
		{
			line_env = ft_strdup(var->env[i]);
			line_env = ft_strchr(line_env, (char)'=') + 1;
			*tab_path = ft_strsplit(line_env, ':');
			return (i);
		}
		i++;
	}
	return (-1);
}

void	execute_cmd(t_list *var, char **tab_pa, char **tab_line, int pos_pa)
{
	char	*str;
	int		i;
	pid_t	child;
	int		status;

	child = fork();
	i = 0;
	if (child == 0)
	{
		while (tab_pa[i])
		{
			str = ft_strdup(tab_pa[i]);
			str = ft_strjoin(str, "/");
			str = ft_strjoin(str, tab_line[0]);
			execve(str, tab_line, &(var->env[pos_pa]));
			i++;
			free(str);
		}
		execve(tab_line[0], tab_line, (var->env));
		error(tab_line[0]);
	}
	else
		wait(&status);
}

int		find_bultins(char *str)
{
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	if (ft_strcmp(str, "setenv") == 0)
		return (2);
	if (ft_strcmp(str, "unsetenv") == 0)
		return (3);
	if (ft_strcmp(str, "env") == 0)
		return (4);
	if (ft_strcmp(str, "exit") == 0)
		return (5);
	return (0);
}

void	ft_minishell(t_list *var, int bultins)
{
	char	**tab_path;
	int		check;
	char	*line;
	char	**tab_line;

	while (42)
	{
		ft_putstr("\033[35;01mMinishell=\033[00m");
		if (get_next_line(0, &line) == 0)
			quit();
		if (my_epur(line) > 0)
			check = looking_for_path(var, &tab_path, line);
		if (my_epur(line) > 0 && check != -1)
		{
			tab_line = ft_strsplit(line, ' ');
			if ((bultins = find_bultins(tab_line[0])) > 0)
			{
				if (bultins == 5)
					ft_exit(tab_line);
				var->env = execute_bultins(var, tab_line, bultins);
			}
			else if (my_epur(line) > 0)
				execute_cmd(var, tab_path, tab_line, check);
		}
	}
}

int		main(int ac, char **av, char **env)
{
	t_list	var;

	(void)ac;
	(void)av;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, quit);
	var.env = NULL;
	if (env[0] != NULL)
	{
		var.env = copy_env(env);
		ft_minishell(&var, 42);
	}
	else
		ft_minishell(&var, 42);
	return (0);
}
