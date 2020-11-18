/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:06:37 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:50 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	if ((char)ch == '\0')
		return (((char *)str) + ft_strlen(str));
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	return (0);
}
