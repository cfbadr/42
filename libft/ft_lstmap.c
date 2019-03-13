/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:18:54 by bchoukri          #+#    #+#             */
/*   Updated: 2015/12/29 14:18:55 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *prov_new_list;
	t_list *new_list;

	if (!lst)
		return (NULL);
	if (!(new_list = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new_list = f(lst);
	prov_new_list = new_list;
	while (lst->next)
	{
		prov_new_list->next = f(lst->next);
		prov_new_list = prov_new_list->next;
		lst = lst->next;
	}
	return (new_list);
}
