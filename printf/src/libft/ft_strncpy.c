/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:18:42 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:50 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;
	int	len_src;

	i = 0;
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	while (len_src && len)
	{
		dst[i] = src[i];
		len_src--;
		i++;
		len--;
	}
	while (len)
	{
		dst[i] = '\0';
		len--;
		i++;
	}
	return (dst);
}
