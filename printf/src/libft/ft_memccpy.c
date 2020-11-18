/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:56:15 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:51 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void				*ft_memccpy(void *dst, const void *src, int ch,\
size_t count)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;
	unsigned char	c;
	size_t			n;

	n = 0;
	ptr_d = (unsigned char *)dst;
	ptr_s = (unsigned char *)src;
	c = (unsigned char)ch;
	while (n < count)
	{
		*ptr_d = *ptr_s;
		if (*ptr_s == c)
		{
			ptr_d++;
			ptr_s++;
			return (ptr_d);
		}
		ptr_d++;
		ptr_s++;
		n++;
	}
	return (NULL);
}
