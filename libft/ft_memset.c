/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:03:33 by hlikely           #+#    #+#             */
/*   Updated: 2019/09/18 19:50:48 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	unsigned char *pointer;

	pointer = (unsigned char *)buf;
	while (count-- > 0)
		*(pointer++) = (unsigned char)ch;
	return (buf);
}
