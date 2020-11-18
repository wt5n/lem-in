/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:26:55 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	di_print_without_minus1(t_printf *list, long long x)
{
	char	*t;

	while (list->widthofline > list->widthofcontent)
	{
		if (list->flags[4] == '0')
		{
			if (x < 0)
			{
				ft_putchar_cow('-', list);
				x *= -1;
				list->widthofcontent--;
				list->widthofline--;
			}
			ft_putchar_cow('0', list);
		}
		else
			ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if (list->len_of_x > 0)
	{
		t = adv_ft_itoa(x, 10, 'a');
		ft_putstr_cow(t, list);
		free(t);
	}
}

void		di_print_without_minus(t_printf *list, long long x)
{
	if ((list->flags[2] == ' ') && list->width >= list->len_of_x && (int)x >= 0)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	while (list->widthofline > list->widthofcontent && \
		((list->precision < list->len_of_x && list->np == 'n') || \
		(list->flags[4] != '0')))
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
	di_print_without_minus1(list, x);
}

static void	one_more_func(t_printf *list, long long x)
{
	if (list->flags[0] == '+' && list->flags[2] == ' ')
		list->flags[2] = '\0';
	if (list->precision == 0 && list->np == 'n' && x == 0)
		list->len_of_x = 0;
	if (list->width > list->len_of_x)
		list->widthofline = list->width;
	else
	{
		if (list->precision > list->len_of_x && list->precision > list->width)
			list->widthofline = list->precision;
		else
			list->widthofline = list->len_of_x;
	}
	if (list->precision < list->len_of_x)
		list->widthofcontent = list->len_of_x;
	else
		list->widthofcontent = list->precision;
	if (list->flags[0] == '+' && x >= 0)
	{
		if (list->np == 'n' && list->precision > 0)
			list->widthofcontent++;
		else if (list->widthofline > list->widthofcontent)
			list->widthofcontent++;
	}
}

void		type_di(t_printf *list)
{
	long long x;

	if (ft_strcmp(list->length, "l") == 0)
		x = (long)va_arg(list->ap, long int);
	else if (ft_strcmp(list->length, "ll") == 0)
		x = (long long)va_arg(list->ap, long long int);
	else if (ft_strcmp(list->length, "hh") == 0)
		x = (signed char)va_arg(list->ap, int);
	else if (ft_strcmp(list->length, "h") == 0)
		x = (short)va_arg(list->ap, int);
	else
		x = (int)va_arg(list->ap, long int);
	list->len_of_x = ft_len_of_int(x);
	one_more_func(list, x);
	while (list->widthofline <= list->widthofcontent && \
	list->flags[2] == ' ' && x >= 0)
		list->widthofline++;
	if ((list->flags[1] == '-') && (list->width > list->widthofcontent))
		di_print_with_minus(list, x);
	else if (list->precision > list->len_of_x - 1)
		presicion_over_len(list, x);
	else
		di_print_without_minus(list, x);
}
