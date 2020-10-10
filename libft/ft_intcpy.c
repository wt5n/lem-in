/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:07:49 by hlikely           #+#    #+#             */
/*   Updated: 2020/08/10 16:46:21 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_intcpy(int *str1, int *str2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = str2[i];
	return (str1);
}
