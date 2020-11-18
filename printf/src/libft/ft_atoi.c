/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:19:18 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned long long	max_min(char *s, int sign)
{
	unsigned long long		re;
	int						i;

	i = 0;
	re = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		re = (re * 10) + (s[i] - '0');
		i++;
	}
	if (sign == -1)
	{
		if (re >= 9223372036854775807)
			return (0);
	}
	if (re >= 9223372036854775807)
		return (-1);
	return (re);
}

int							ft_atoi(const char *str)
{
	char					*s;
	unsigned long long		r;
	int						sign;
	int						i;

	r = 0;
	s = (char *)str;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' ||\
	s[i] == '\f' || s[i] == '\r' || s[i] == '\v')
		i++;
	sign = (s[i] == '-') ? -1 : 1;
	s = (s[i] == '+' || s[i] == '-') ? s + 1 : s;
	r = max_min(s + i, sign);
	return ((int)r * sign);
}
