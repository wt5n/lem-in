/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:22:56 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		withnull(char *str, char *res, int len, int x)
{
	int		j;
	int		ch;

	j = 0;
	ch = 10 - len;
	while (len-- > 0)
	{
		res[x] = '0';
		x++;
	}
	while (0 < ch--)
	{
		res[x] = str[j];
		x++;
		j++;
	}
	return (x);
}

char	*full_str(unsigned long long *arr, int i)
{
	int		x;
	int		j;
	int		len;
	char	*res;
	char	*str;

	x = 0;
	if (!(res = (char*)malloc(sizeof(char) * ((15 - i) * 10) + 1)))
		return (NULL);
	res[(15 - i) * 10] = '\0';
	while (i < 15)
	{
		str = adv_ft_itoa(arr[i], 10, 'a');
		len = 10 - ft_strlen(str);
		j = 0;
		if (len)
			x = withnull(str, res, len, x);
		else
			while (j < 10)
				res[x++] = str[j++];
		i++;
		free(str);
	}
	return (res);
}

int		ap_number(t_double d1, unsigned long long *arr, int countofel, int pow)
{
	int		i;
	int		n;

	i = 0;
	while (i < countofel)
		arr[i++] = 0;
	addit(arr, countofel - 1, d1.part.m);
	while (pow--)
		mult(arr, 0, 5, countofel);
	addit(arr, 9, 100);
	pow = d1.part.e - 1023;
	if (pow > 0)
		while (pow--)
			mult(arr, 0, 2, countofel);
	else
	{
		while (pow < 0)
		{
			mult(arr, 0, 5, countofel);
			pow++;
		}
	}
	n = d1.part.e - 1023;
	return (n < 0 ? n : 0);
}

void	handling_float_part2(t_printf *list, char *tmp, long long n, int s)
{
	while (*tmp == '0' && n > 1)
	{
		tmp++;
		n--;
	}
	if (s || list->floatminimum)
		ft_putchar_cow('-', list);
	if (list->floatzero)
	{
		ft_putchar_cow('0', list);
		n--;
		tmp++;
	}
	if (((list->precision == 0 && list->np == 'n') || list->precision))
		rounding(tmp, list->precision + n);
	while (n > 0)
	{
		ft_putchar_cow(*tmp++, list);
		n--;
	}
	if (list->precision || list->flags[3] == '#')
		ft_putchar_cow('.', list);
	while (list->precision--)
		ft_putchar_cow(*tmp++, list);
}

void	handling_float(long double d, int countofel, int pow, t_printf *list)
{
	t_double			d1;
	unsigned long long	*arr;
	int					i;
	char				*tmp;
	long long			n;

	if (d == 0 || d == __DBL_MIN__ || d == -__DBL_MIN__)
	{
		nulz(d, list);
		return ;
	}
	n = 98;
	d1.d = d;
	arr = (unsigned long long*)malloc(sizeof(unsigned long long) * countofel);
	n += ap_number(d1, arr, countofel, pow);
	i = 0;
	while (arr[i] == 0 && n > 10)
	{
		i++;
		n -= 10;
	}
	tmp = full_str(arr, i);
	handling_float_part2(list, tmp, n, d1.part.s);
	free(arr);
	free(tmp);
}
