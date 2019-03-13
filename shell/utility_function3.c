/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_function3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 02:29:26 by bchoukri          #+#    #+#             */
/*   Updated: 2015/06/11 17:18:48 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"
#include "libft.h"
#include <stdio.h>

int			my_epur(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] != '\t' && str[i] != ' ') && str[i] != '\0')
			j++;
		i++;
	}
	return (j);
}

int			find_pos(t_list *var, char *str)
{
	int		i;
	int		len;
	int		check;

	check = 0;
	str = ft_strjoin(str, "=");
	len = ft_strlen(str);
	i = 0;
	while (var->env[i] && check == 0)
	{
		if (ft_strncmp(str, var->env[i], len) == 0)
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (check == 1)
		return (i);
	return (-1);
}

void		ft_block_sig(void)
{

}

void		free_double_tabv2(t_list *var)
{
	int		i;

	i = 0;
	while (var->env[i])
	{
		free(var->env[i]);
		i++;
	}
	free(var->env);
}
