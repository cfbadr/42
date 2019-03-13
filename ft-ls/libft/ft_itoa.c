/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 15:12:34 by bchoukri          #+#    #+#             */
/*   Updated: 2015/02/03 10:58:04 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		eror_intlen(int value)
{
	int len;

	len = 0;
	if (value < 0)
		len++;
	while (value)
	{
		len++;
		value /= 10;
	}
	return (len);
}

static char		*eror_intmax(void)
{
	char *temp;

	temp = ft_strnew(eror_intlen(-2147483648) + 1);
	ft_strcpy(temp, "-2147483648");
	return (temp);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (eror_intmax());
	str = ft_strnew(eror_intlen(n) + 1);
	i = eror_intlen(n) - 1;
	if (str)
	{
		if (n < 0)
		{
			str[0] = '-';
			n *= -1;
		}
		if (n == 0)
			*str = '0';
		while (n > 0)
		{
			str[i] = '0' + (n % 10);
			n /= 10;
			i--;
		}
	}
	return (str);
}
