/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:48:41 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/12 16:30:28 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *buf, size_t count)
{
	unsigned char *pointer;

	pointer = (unsigned char *)buf;
	while (count-- > 0)
		*(pointer++) = 0;
}
