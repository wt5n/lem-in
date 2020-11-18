/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:12:52 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 00:37:21 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			ft_intlen(unsigned int nb)
{
	unsigned int	s;

	s = 1;
	while (nb >= 10)
	{
		nb /= 10;
		s++;
	}
	return (s);
}

char				*ft_itoa(int nbr)
{
	char			*str;
	unsigned int	nb;
	int				i;
	unsigned int	size;

	nb = nbr < 0 ? (unsigned int)(nbr * -1) : (unsigned int)nbr;
	size = (unsigned int)ft_intlen(nb);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1 + (nbr < 0 ? 1 : 0)))))
		return (0);
	if (nbr < 0 && (str[i] = '-'))
		size++;
	i = size - 1;
	while (nb >= 10)
	{
		str[i--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[i] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
