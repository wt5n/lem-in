/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:47:17 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:49 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t len;

	len = 0;
	while (len < maxlen)
	{
		if (!*s)
			break ;
		len++;
		maxlen++;
	}
	return (len);
}
