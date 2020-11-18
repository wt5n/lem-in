/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:52:53 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		f_print_with_minus(t_printf *list, long double x)
{
	if ((list->flags[0] == '+') && (int)x >= 0)
	{
		ft_putchar_cow('+', list);
		list->widthofline--;
		list->widthofcontent--;
	}
	if ((list->flags[2] == ' ') && (int)x >= 0)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if ((int)x < 0)
	{
		ft_putchar_cow('-', list);
		x *= -1;
		if (list->precision > list->len_of_x)
			list->widthofline--;
	}
	if (list->len_of_x > 0)
		list->len_of_x = ft_len_of_int(x);
	f_print_with_minus1(list, x);
}

void		f_presicion_over_len(t_printf *list, long double x)
{
	if (list->width > list->precision && (int)x < 0)
		list->widthofline--;
	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if ((list->flags[0] == '+') && x >= 0)
	{
		ft_putchar_cow('+', list);
		list->widthofline--;
		list->widthofcontent--;
	}
	f_presicion_over_len1(list, x);
}

void		f_print_without_minus(t_printf *list, long double x)
{
	if ((list->flags[2] == ' ') && \
		list->widthofcontent >= list->len_of_x && (int)x >= 0)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	while (list->widthofline > list->widthofcontent && \
		(list->flags[4] != '0'))
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if ((list->flags[0] == '+') && x >= 0)
	{
		ft_putchar_cow('+', list);
		list->widthofline--;
		list->widthofcontent--;
	}
	f_print_without_minus1(list, x);
}

static void	partofthesystem(t_printf *list, long double x)
{
	if (list->flags[0] == '+' && list->flags[2] == ' ')
		list->flags[2] = '\0';
	if (list->width > list->len_of_x)
		list->widthofline = list->width;
	else
	{
		if (list->precision > list->len_of_x && list->precision > list->width)
			list->widthofline = list->precision;
		else
			list->widthofline = list->len_of_x;
	}
	list->widthofcontent = list->len_of_x;
	if (list->flags[0] == '+' && x >= 0)
	{
		if (list->np == 'n' && list->precision > 0)
			list->widthofcontent++;
		else if (list->widthofline > list->widthofcontent)
			list->widthofcontent++;
	}
}

void		type_f(t_printf *list)
{
	long double	x;

	if (ft_strcmp(list->length, "L") == 0)
		x = (long double)va_arg(list->ap, long double);
	else
		x = va_arg(list->ap, double);
	list->len_of_x = (x != 0) ? ft_len_of_int(x) + list->precision : 8;
	partofthesystem(list, x);
	if (list->flags[3] == '#' && list->precision == 0)
		list->widthofline--;
	if (list->precision > 0)
	{
		if (list->widthofline == list->widthofcontent)
			list->widthofline++;
		list->widthofcontent++;
	}
	while (list->widthofline <= list->widthofcontent && \
	list->flags[2] == ' ' && x >= 0)
		list->widthofline++;
	if ((list->flags[1] == '-') && (list->width > list->widthofcontent))
		f_print_with_minus(list, x);
	else if (list->precision > list->len_of_x - 1)
		f_presicion_over_len(list, x);
	else
		f_print_without_minus(list, x);
}
