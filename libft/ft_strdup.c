/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:10:50 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/12 16:30:28 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*a;
	int		i;
	int		buf;

	i = 0;
	buf = 0;
	while (str[buf])
		buf++;
	if (!(a = malloc(sizeof(char) * (buf + 1))))
		return (NULL);
	while (str[i])
	{
		a[i] = str[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
