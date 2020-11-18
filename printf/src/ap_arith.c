/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_arith.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:21:39 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	addit(unsigned long long *arr, int i, unsigned long long num)
{
	unsigned long long x;

	x = 10000000000;
	arr[i] += num % x;
	if (arr[i] + num % x > 999999999 || num / x > 0)
		addit(arr, i - 1, num / x);
}

void	mult(unsigned long long *arr, int i, int num, int end)
{
	unsigned long long x;
	unsigned long long res;

	if (i == end)
		return ;
	x = 10000000000;
	res = arr[i] * num;
	if (res > 999999999)
		addit(arr, i - 1, res / x);
	arr[i] = res % x;
	mult(arr, i + 1, num, end);
}

void	divis(unsigned long long *arr, int i, int num)
{
	unsigned long long	res;
	unsigned long long	cell;
	unsigned long long	x;
	int					end;

	x = 10000000000;
	end = i;
	res = 0;
	i = 0;
	while (arr[i] == 0 && i < end)
		i++;
	cell = arr[i];
	while (i <= end)
	{
		res = (cell / num);
		cell = ((arr[i] % num) * x) + arr[i + 1];
		arr[i] = res;
		i++;
	}
}

void	rounding(char *tmp, int p)
{
	if (tmp[p] - 48 >= 5)
	{
		p--;
		if (tmp[p] != '9')
			tmp[p] += 1;
		else
		{
			while (tmp[p] == '9')
			{
				tmp[p] = '0';
				p--;
				if (tmp[p] != '9')
				{
					tmp[p] += 1;
					break ;
				}
			}
		}
	}
}
