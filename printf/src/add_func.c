/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:55:50 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putchar_cow(char c, t_printf *list)
{
	write(1, &c, 1);
	list->cow++;
}

void	ft_putstr_cow(char const *s, t_printf *list)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return ;
	i = ft_strlen(s);
	write(1, s, i);
	list->cow += i;
}

void	sharp_x(t_printf *list)
{
	if (list->flags[3] == '#' && list->type == 'o')
	{
		ft_putchar_cow('0', list);
		list->widthofline--;
		list->widthofcontent--;
		list->len_of_x--;
	}
	else if (list->flags[3] == '#' && list->type == 'x')
	{
		ft_putstr_cow("0x", list);
		list->widthofline -= 2;
		list->widthofcontent -= 2;
		list->len_of_x -= 2;
	}
	else if (list->flags[3] == '#' && list->type == 'X')
	{
		ft_putstr_cow("0X", list);
		list->widthofline -= 2;
		list->widthofcontent -= 2;
		list->len_of_x -= 2;
	}
}

size_t	ft_len_of_int(long long i)
{
	size_t	res;

	res = 1;
	if (i < 0)
	{
		i *= -1;
		res++;
	}
	while (i >= 10)
	{
		res++;
		i /= 10;
	}
	return (res);
}

void	stars(t_printf *list)
{
	int	x;

	x = (unsigned int)va_arg(list->ap, unsigned long int);
	if (list->nw == 'n' && list->f_copy[list->i] == '*')
	{
		list->width = x;
		list->i++;
	}
	else if (list->f_copy[list->i] == '.')
	{
		list->precision = x;
		list->i += 2;
	}
}
