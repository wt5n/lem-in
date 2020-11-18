/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:07:22 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	one_more_func(t_printf *list, long long x)
{
	char *t;

	while (list->precision > list->len_of_x)
	{
		ft_putchar_cow('0', list);
		list->precision--;
	}
	if (list->len_of_x > 0)
	{
		t = adv_ft_itoa(x, 10, 'a');
		ft_putstr_cow(t, list);
		list->widthofline -= list->len_of_x;
		list->widthofcontent -= list->len_of_x;
		free(t);
	}
	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
}

void		di_print_with_minus(t_printf *list, long long x)
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
	one_more_func(list, x);
}

static void	one_more_func1(t_printf *list, long long x)
{
	char	*t;

	if (x < 0)
	{
		ft_putchar_cow('-', list);
		x *= -1;
		list->widthofline--;
	}
	while (list->widthofcontent > ft_len_of_int(x))
	{
		ft_putchar_cow('0', list);
		list->widthofcontent--;
	}
	if (list->len_of_x > 0)
	{
		t = adv_ft_itoa(x, 10, 'a');
		ft_putstr_cow(t, list);
		free(t);
	}
}

void		presicion_over_len(t_printf *list, long long x)
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
	one_more_func1(list, x);
}
