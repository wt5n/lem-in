/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:16:00 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

size_t		lennum_base(long long n, int base)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= base)
	{
		n /= base;
		i++;
	}
	return (i);
}

char		size_of_letter(char c)
{
	if (c >= 'a')
		return ('a');
	return ('A');
}

char		*kraynie(size_t len, long long n)
{
	char	*res;
	char	*str;

	if (len == 0)
		str = "";
	if (n == 0)
		str = "0";
	else
		str = "-9223372036854775808";
	res = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	ft_strcpy(res, str);
	return (res);
}

char		*adv_ft_itoa(long long n, int base, char c)
{
	char	*res;
	size_t	len;

	len = lennum_base(n, base);
	if (len == 0 || n == 0 || n == LONG_MIN)
		return (kraynie(len, n));
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len--] = '\0';
	if (n < 0)
		res[0] = '-';
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		if (n % base > 9)
			res[len--] = (n % base) + (size_of_letter(c) - 10);
		else
			res[len--] = (n % base) + '0';
		n /= base;
	}
	return (res);
}
