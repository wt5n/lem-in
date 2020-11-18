/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:17:42 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		display_gap(t_printf *list, char c, int len, int update_len)
{
	char	*str;

	if (len > 0)
	{
		if (update_len)
			list->cow += len;
		if (!(str = ft_strnew(len)))
			exit(-1);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
}

static void	type_perc(t_printf *list)
{
	if (list->flags[4] == '0' && list->precision <= 0 && !list->flags[1])
	{
		list->precision = list->width;
		list->width = 0;
	}
	if (list->flags[1] != '-')
		display_gap(list, ' ', list->width - 1, 1);
	if (list->flags[4] == '0')
		display_gap(list, '0', list->precision - 1, 1);
	write(1, "%", 1);
	if (list->flags[1] == '-')
		display_gap(list, ' ', list->width - 1, 1);
	list->cow++;
}

void		type_other(t_printf *list)
{
	if (list->type == '%')
		type_perc(list);
	else
		ft_putstr_cow(list->f_copy, list);
}
