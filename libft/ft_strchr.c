/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:06:37 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/12 16:30:28 by hlikely          ###   ########.fr       */
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
