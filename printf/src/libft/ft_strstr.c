/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:22:15 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:51 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	unsigned int ptr1;
	unsigned int ptr2;

	ptr1 = 0;
	ptr2 = 1;
	if (!*str2)
		return ((char *)str1);
	while (str1[ptr1] != '\0')
	{
		if (str1[ptr1] == str2[0])
		{
			while (str2[ptr2] != '\0' && str1[ptr1 + ptr2] == str2[ptr2])
				ptr2++;
			if (str2[ptr2] == '\0')
				return ((char *)&str1[ptr1]);
		}
		ptr1++;
	}
	return (0);
}
