/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:58:51 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	f_print_with_minus1(t_printf *list, long double x)
{
	while (list->precision > list->len_of_x)
	{
		ft_putchar_cow('0', list);
		list->precision--;
	}
	if (list->len_of_x > 0)
	{
		if (ft_strcmp(list->length, "L") == 0)
			handling_float_lf(x, 15, 63, list);
		else
			handling_float(x, 15, 52, list);
		list->widthofline -= list->len_of_x;
		list->widthofcontent -= list->len_of_x;
	}
	while (list->widthofline > list->widthofcontent)
	{
		ft_putchar_cow(' ', list);
		list->widthofline--;
	}
}

void	f_presicion_over_len1(t_printf *list, long double x)
{
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
	if (ft_strcmp(list->length, "L") == 0)
		handling_float_lf(x, 15, 63, list);
	else
		handling_float(x, 15, 52, list);
}

void	f_print_without_minus1(t_printf *list, long double x)
{
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
	if (ft_strcmp(list->length, "L") == 0)
		handling_float_lf(x, 15, 63, list);
	else
		handling_float(x, 15, 52, list);
}
