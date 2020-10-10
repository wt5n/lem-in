/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:58:42 by hlikely           #+#    #+#             */
/*   Updated: 2019/09/22 20:37:57 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char*)buf1;
	ptr2 = (unsigned char*)buf2;
	while (count--)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		++ptr1;
		++ptr2;
	}
	return (0);
}
