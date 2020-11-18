/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:17:03 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:51 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t count)
{
	int		i;
	size_t	n;

	i = 0;
	n = 0;
	while (str1[i] != '\0')
		i++;
	while (str2[n] != '\0' && n < count)
	{
		str1[i] = str2[n];
		i++;
		n++;
	}
	str1[i] = '\0';
	return (str1);
}
