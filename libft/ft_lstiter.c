/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:18:31 by bchoukri          #+#    #+#             */
/*   Updated: 2015/12/29 14:18:32 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_lstiter(t_list *lst, void (f)(t_list *elem))
{
	t_list *list;

	if (lst)
	{
		list = lst;
		while (list)
		{
			f(list);
			list = list->next;
		}
	}
}
