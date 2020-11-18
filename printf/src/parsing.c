/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:47:52 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	*flag(t_printf *list)
{
	size_t i;

	i = 0;
	while (list->cons[i] != '\0')
	{
		while (list->cons[i] == list->f_copy[list->i])
		{
			while (list->f_copy[list->i] == '+' && list->i++)
				list->flags[0] = '+';
			while (list->f_copy[list->i] == '-' && list->i++)
				list->flags[1] = '-';
			while (list->f_copy[list->i] == ' ' && list->i++)
				list->flags[2] = ' ';
			while (list->f_copy[list->i] == '#' && list->i++)
				list->flags[3] = '#';
			while (list->f_copy[list->i] == '0' && list->i++)
				list->flags[4] = '0';
			i = 0;
		}
		i++;
	}
	return (width(list));
}

t_printf	*width(t_printf *list)
{
	int	num;

	if (list->f_copy[list->i] >= '0' && list->f_copy[list->i] <= '9')
	{
		num = ft_atoi(&list->f_copy[list->i]);
		list->width = num;
		while (num > 0)
		{
			list->i++;
			num /= 10;
		}
	}
	else if (list->f_copy[list->i] == '*')
		stars(list);
	else
		list->nw = 'y';
	return (precision(list));
}

t_printf	*precision(t_printf *list)
{
	if (list->f_copy[list->i] == '.' && list->f_copy[list->i + 1] != '*')
	{
		list->i++;
		while (list->f_copy[list->i] >= '0' && list->f_copy[list->i] <= '9')
		{
			list->precision *= 10;
			list->precision += (list->f_copy[list->i] - 48);
			list->i++;
		}
	}
	else if (list->f_copy[list->i + 1] == '*')
		stars(list);
	else
		list->np = 'y';
	return (length(list));
}

t_printf	*length(t_printf *list)
{
	size_t	i;

	i = 0;
	while (list->args[i] != '\0')
	{
		if (list->args[i] == list->f_copy[list->i])
		{
			list->length[0] = list->f_copy[list->i];
			list->i++;
			if (list->f_copy[list->i] == list->length[0])
			{
				list->length[1] = list->length[0];
				list->i++;
			}
		}
		i++;
	}
	return (type(list));
}

t_printf	*type(t_printf *list)
{
	size_t	i;

	i = 0;
	while (list->types[i] != '\0')
	{
		if (list->types[i] == list->f_copy[list->i])
		{
			list->type = list->types[i];
			break ;
		}
		i++;
	}
	if (list->type == 'x' || list->type == 'X')
		list->base = 16;
	else if (list->type == 'o')
		list->base = 8;
	else if (list->np == 'y' && (list->type == 'f' || list->type == 'F'))
		list->precision = 6;
	return (list);
}
