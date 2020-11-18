/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:19:50 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:50 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = '\0';
	return (str);
}
