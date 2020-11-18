/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:15:22 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:51 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *p;
	char *t;
	char *r;

	if (!s || !f)
		return (NULL);
	r = ft_memalloc(ft_strlen((char *)s) + 1);
	if (!r)
		return (NULL);
	p = (char *)s;
	t = r;
	while (*p)
		*(t++) = f(*(p++));
	return (r);
}
