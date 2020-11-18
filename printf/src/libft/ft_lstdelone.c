/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:18:51 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:04:52 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **link, void (*del)(void *, size_t))
{
	del((*link)->content, (*link)->content_size);
	free(*link);
	*link = NULL;
}
