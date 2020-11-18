/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:29:52 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:49 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		k;
	size_t		i;
	size_t		j;
	size_t		n;
	char		*res;

	i = 0;
	n = ft_strlen(little);
	if (!little[i])
		return ((char*)big);
	while (big[i] != '\0' && i < (len - n + 1))
	{
		j = i;
		k = 0;
		res = ((char*)&big[j]);
		while (big[j] == little[k++] && j < len)
		{
			j++;
			if (!little[k])
				return (res);
		}
		i++;
	}
	return (NULL);
}
