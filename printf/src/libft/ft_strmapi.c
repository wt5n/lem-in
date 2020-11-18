/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:16:10 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:51 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*r;

	if (!s || !(r = ft_memalloc((size_t)ft_strlen((char *)s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = f(i, s[i]);
		i++;
	}
	return (r);
}
