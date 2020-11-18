/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:03:54 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		b_print_with_minus(t_printf *l, long long x)
{
	char *t;

	while (l->precision > l->len_of_x)
	{
		ft_putchar_cow('0', l);
		l->precision--;
		l->widthofline--;
	}
	if (l->flags[3] == '#' && l->len_of_x > 0 && l->widthofline > 1 && x != 0)
		sharp_x(l);
	if (l->len_of_x > 0)
		l->len_of_x = lennum_base(x, l->base);
	if (l->len_of_x > 0 || (l->flags[3] == '#'))
	{
		t = adv_ft_itoa(x, l->base, l->type);
		ft_putstr_cow(t, l);
		l->widthofline -= lennum_base(x, l->base);
		l->widthofcontent -= lennum_base(x, l->base);
	}
	while (l->widthofline > 0)
	{
		ft_putchar_cow(' ', l);
		l->widthofline--;
	}
	free(t);
}

void		b_presicion_over_len(t_printf *list, long long x)
{
	char *t;

	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if (list->flags[3] == '#' && list->len_of_x > 0 && x != 0)
		sharp_x(list);
	while (list->widthofcontent > list->len_of_x)
	{
		ft_putchar_cow('0', list);
		list->widthofcontent--;
	}
	t = adv_ft_itoa(x, list->base, list->type);
	if (list->len_of_x > 0)
		ft_putstr_cow(t, list);
	free(t);
}

void		b_print_without_minus(t_printf *list, long long x)
{
	char *t;

	while (list->widthofline > list->widthofcontent && ((list->precision \
		< list->len_of_x && list->np == 'n') || (list->flags[4] != '0')))
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	if (list->flags[3] == '#' && list->len_of_x > 0 && x != 0)
		sharp_x(list);
	while (list->widthofline > list->widthofcontent)
	{
		list->flags[4] == '0' ? ft_putchar_cow('0', list)\
		: ft_putchar_cow(' ', list);
		list->widthofline--;
	}
	t = adv_ft_itoa(x, list->base, list->type);
	if (list->len_of_x > 0 || (list->flags[3] == '#'))
		ft_putstr_cow(t, list);
	free(t);
}

static void	one_more_func(t_printf *list, unsigned long x)
{
	if (list->precision == 0 && list->np == 'n' && (list->flags[3] != '#'))
		list->len_of_x = 0;
	if ((list->flags[3] == '#') && x != 0)
		list->len_of_x++;
	if (list->width > list->len_of_x)
		list->widthofline = list->width;
	else
	{
		if (list->precision < list->len_of_x && list->precision > 0)
			list->widthofline = list->precision;
		else
			list->widthofline = list->len_of_x;
	}
	if (list->precision < list->len_of_x)
		list->widthofcontent = list->len_of_x;
	else
		list->widthofcontent = list->precision;
}

void		type_b(t_printf *list)
{
	unsigned long x;

	if (ft_strcmp(list->length, "l") == 0)
		x = (unsigned long)va_arg(list->ap, unsigned long int);
	else if (ft_strcmp(list->length, "ll") == 0)
		x = (unsigned long long)va_arg(list->ap, unsigned long long int);
	else if (ft_strcmp(list->length, "hh") == 0)
		x = (unsigned char)va_arg(list->ap, unsigned int);
	else if (ft_strcmp(list->length, "h") == 0)
		x = (unsigned short)va_arg(list->ap, unsigned int);
	else
		x = (unsigned int)va_arg(list->ap, unsigned long int);
	list->base = 2;
	list->len_of_x = lennum_base(x, list->base);
	one_more_func(list, x);
	if ((list->flags[1] == '-') && (list->width > list->widthofcontent))
		b_print_with_minus(list, x);
	else if (list->precision > list->len_of_x - 1)
		b_presicion_over_len(list, x);
	else
		b_print_without_minus(list, x);
}
