/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:38:50 by bchoukri          #+#    #+#             */
/*   Updated: 2015/12/16 16:40:01 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intcmp(time_t nb1, time_t nb2, char *str1, char *str2)
{
	if (nb1 < nb2)
		return (-1);
	else if (nb1 > nb2)
		return (1);
	if (ft_strcmp(str1, str2) < 0)
		return (1);
	return (-1);
}
