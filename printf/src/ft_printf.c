/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:25:19 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		reset_list(t_printf *list)
{
	list->width = 0;
	list->precision = 0;
	list->length[0] = 'Q';
	list->length[1] = '\0';
	list->length[2] = '\0';
	list->type = 'Q';
	list->flags[0] = '\0';
	list->flags[1] = '\0';
	list->flags[2] = '\0';
	list->flags[3] = '\0';
	list->flags[4] = '\0';
	list->widthofline = 0;
	list->widthofcontent = 0;
	list->base = 10;
	list->np = 'n';
	list->nw = 'n';
	list->len_of_x = 0;
	list->floatzero = 0;
	list->floatminimum = 0;
}

int			init(t_printf *list)
{
	while (list->f_copy[list->i] != '\0')
	{
		if (list->f_copy[list->i] == '%')
		{
			list->i++;
			flag(list);
			if (list->type == 'Q')
				return (0);
			display(list);
			reset_list(list);
		}
		else
		{
			write(1, &list->f_copy[list->i], 1);
			list->cow++;
		}
		list->i++;
	}
	return (list->cow);
}

t_printf	*newlist_with_printf(t_printf *list)
{
	list->width = 0;
	list->precision = 0;
	list->length[0] = 'Q';
	list->length[1] = '\0';
	list->length[2] = '\0';
	list->type = 'Q';
	list->flags[0] = '\0';
	list->flags[1] = '\0';
	list->flags[2] = '\0';
	list->flags[3] = '\0';
	list->flags[4] = '\0';
	list->widthofline = 0;
	list->widthofcontent = 0;
	list->base = 10;
	list->cow = 0;
	list->np = 'n';
	list->nw = 'n';
	list->i = 0;
	list->types = "aAbcCeEgGsSnpdifFuUoxX%";
	list->cons = "+- #0";
	list->args = "lhjzL";
	list->len_of_x = 0;
	list->floatzero = 0;
	list->floatminimum = 0;
	return (list);
}

void		display(t_printf *list)
{
	if (list->type == 'd' || list->type == 'i')
		type_di(list);
	else if (list->type == 'c' || list->type == 'C')
		type_c(list);
	else if (list->type == 'f' || list->type == 'F')
		type_f(list);
	else if (list->type == 's' || list->type == 'S')
		type_s(list);
	else if (list->type == 'u' || list->type == 'U')
		type_u(list);
	else if (list->type == 'x' || list->type == 'X')
		type_x(list);
	else if (list->type == 'o')
		type_o(list);
	else if (list->type == 'p')
		type_p(list);
	else if (list->type == 'b')
		type_b(list);
	else
		type_other(list);
}

int			ft_printf(const char *format, ...)
{
	t_printf	*list;
	int			i;

	if (!(list = (t_printf*)malloc(sizeof(t_printf))))
		return (-1);
	list->format = format;
	list = newlist_with_printf(list);
	if (format)
	{
		va_start(list->ap, format);
		list->f_copy = (char *)list->format;
		list->cow = init(list);
		va_end(list->ap);
	}
	i = list->cow;
	free(list);
	return (i);
}
