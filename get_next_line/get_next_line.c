/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 10:21:55 by bchoukri          #+#    #+#             */
/*   Updated: 2015/02/25 14:38:54 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_end_of_line(int const fd, char *buff, char **pos)
{
	int		rd;
	char	*c;

	rd = 0;
	while (!(c = ft_strchr(pos[fd], '\n')))
	{
		rd = read(fd, buff, BUFF_SIZE);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		pos[fd] = ft_strjoin(pos[fd], buff);
	}
	ft_strdel(&buff);
	if (rd == -1)
		return (-1);
	else if (!c && rd == 0)
		return (0);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int			check;
	char		*buff;
	char		*tmp;
	static char	*pos[1];
	int			end;

	buff = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || !buff)
		return (-1);
	if (pos[fd] == NULL)
		pos[fd] = ft_strnew(1);
	check = check_end_of_line(fd, buff, pos);
	if (check <= 0)
	{
		*line = pos[fd];
		return (check);
	}
	end = ft_strchr(pos[fd], '\n') - pos[fd];
	*line = ft_strsub(pos[fd], 0, end);
	tmp = pos[fd];
	pos[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1);
	ft_strdel(&tmp);
	return (1);
}
