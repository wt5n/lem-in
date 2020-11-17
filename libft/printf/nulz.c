/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nulz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:04:22 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/17 21:04:38 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	nulz(long double d, t_printf *list)
{
	if (d == -__DBL_MIN__)
		ft_putchar_cow('-', list);
	ft_putchar_cow('0', list);
	if (list->precision)
		ft_putchar_cow('.', list);
	while (list->precision > 0)
	{
		ft_putchar_cow('0', list);
		list->precision--;
	}
}
