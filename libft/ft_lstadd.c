/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:16:59 by bchoukri          #+#    #+#             */
/*   Updated: 2015/12/29 14:50:45 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd(t_list **alst, t_list *new_lst)
{
	t_list *element;

	if (alst)
	{
		element = *alst;
		new_lst->next = element;
		*alst = new_lst;
	}
}
