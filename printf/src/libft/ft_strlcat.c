/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:14:19 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:50 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (size <= i)
		j += size;
	else
		j += i;
	while (src[k] != '\0' && i + 1 < size)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (j);
}
