/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:34:15 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		str_print_with_minus(t_printf *list, char *str)
{
	while (list->widthofline > 0)
	{
		while (list->widthofcontent)
		{
			ft_putchar_cow(*str, list);
			str++;
			list->widthofline--;
			list->widthofcontent--;
		}
		if (list->widthofline > 0)
		{
			ft_putchar_cow(' ', list);
			list->widthofline--;
		}
	}
}

void		str_print_without_minus(t_printf *list, char *str)
{
	while (list->widthofline > 0)
	{
		while (list->widthofline > list->widthofcontent)
		{
			ft_putchar_cow(' ', list);
			list->widthofline--;
		}
		if (list->widthofline > 0)
		{
			ft_putchar_cow(*str, list);
			str++;
			list->widthofline--;
		}
	}
}

static void	one_more_func(t_printf *list)
{
	if (list->width >= list->len_of_x)
		list->widthofline = list->width;
	else if (list->width < list->len_of_x && list->nw == 'n' && \
			list->precision < list->len_of_x && list->np == 'n' && \
			list->width > list->precision)
		list->widthofline = list->width;
	else if (list->width < list->len_of_x && list->nw == 'n' && \
			list->precision < list->width)
		list->widthofline = list->len_of_x;
	else if (list->precision < list->len_of_x && list->np == 'n')
		list->widthofline = list->precision;
	else
		list->widthofline = list->len_of_x;
	if (list->nw == 'y' && list->precision == 0 && list->np == 'n')
	{
		list->widthofcontent = 0;
		list->widthofline = 0;
	}
	else if (list->precision == 0 && list->np == 'n')
		list->widthofcontent = 0;
	else if (list->precision < list->len_of_x && list->np == 'n')
		list->widthofcontent = list->precision;
	else
		list->widthofcontent = list->len_of_x;
}

void		type_s(t_printf *list)
{
	char	*str;

	str = va_arg(list->ap, char*);
	if (str == 0)
		str = "(null)";
	list->len_of_x = ft_strlen(str);
	one_more_func(list);
	if ((list->flags[1] == '-') && (list->width > list->widthofcontent))
		str_print_with_minus(list, str);
	else
		str_print_without_minus(list, str);
}
