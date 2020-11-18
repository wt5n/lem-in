/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:47:40 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:50 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(int *str, int p, int q)
{
	int		i;
	int		j;

	i = p - 1;
	j = p;
	while (j <= q)
	{
		if (str[j] <= str[q])
			ft_swap(&str[++i], &str[j]);
		j++;
	}
	return (i);
}

void		ft_quicksort(int *str, int p, int q)
{
	int		pivot;

	if (p < q)
	{
		pivot = partition(str, p, q);
		ft_quicksort(str, p, pivot - 1);
		ft_quicksort(str, pivot + 1, q);
	}
}
