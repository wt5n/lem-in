/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:02:31 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:49 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t count)
{
	unsigned char		*ptr_d;
	const unsigned char	*ptr_s;
	size_t				i;

	ptr_d = (unsigned char*)dst;
	ptr_s = (const unsigned char*)src;
	i = 0;
	if (!dst && !src)
		return (0);
	if (count == 0 || dst == src)
		return (dst);
	if (ptr_s < ptr_d)
		while (++i <= count)
			ptr_d[count - i] = ptr_s[count - i];
	else
		while (count-- > 0)
			*(ptr_d++) = *(ptr_s++);
	return (dst);
}
