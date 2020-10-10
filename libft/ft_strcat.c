/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:06:03 by hlikely           #+#    #+#             */
/*   Updated: 2019/09/18 18:06:05 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destptr, const char *srcptr)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (destptr[i] != '\0')
		i++;
	while (srcptr[j] != '\0')
	{
		destptr[i] = srcptr[j];
		i++;
		j++;
	}
	destptr[i] = '\0';
	return (destptr);
}
