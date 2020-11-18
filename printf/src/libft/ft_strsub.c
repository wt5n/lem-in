/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:22:36 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:52 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *r;

	if (!s || !(r = ft_memalloc(len + 1)))
		return (NULL);
	r = ft_strncpy(r, (char *)s + start, len);
	return (r);
}
