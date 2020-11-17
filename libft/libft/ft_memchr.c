/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:56:44 by hlikely           #+#    #+#             */
/*   Updated: 2019/09/18 17:58:07 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buffer, int ch, size_t count)
{
	size_t			i;
	unsigned char	*pointer;

	i = 0;
	pointer = (unsigned char*)buffer;
	while (++i <= count)
		if (*(pointer++) == (unsigned char)ch)
			return ((void *)--pointer);
	return (0);
}
