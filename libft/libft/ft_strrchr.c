/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:21:35 by hlikely           #+#    #+#             */
/*   Updated: 2019/09/24 18:08:15 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	char *ptr;

	ptr = 0;
	while (*string)
	{
		if (*string == symbol)
			ptr = (char *)string;
		string++;
	}
	if (ptr)
		return (ptr);
	if (symbol == '\0')
		return ((char*)string);
	return (0);
}
