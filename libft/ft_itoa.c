/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoukri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 15:12:34 by bchoukri          #+#    #+#             */
/*   Updated: 2015/12/29 14:03:26 by bchoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int char_counter(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char *ft_itoa(int n)
{
	char*str;
	int len;
	int sign;

	sign = 1;
	len = char_counter(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[len] = '\0';
	if (n < 0)
	{
		sign = -1;
		str[0] = '-';
	}
	len = len - 1;
	while (n)
	{
		str[len] = (((n % 10) * sign) + '0');
		len--;
		n = n / 10;
	}
	return (str);
}
/*

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
*/
