/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:29:51 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/16 22:12:37 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

unsigned long	get_hash(unsigned char *name)
{
	unsigned long	hash;
	int				c;

	hash = HASH_ROOMS;
	while ((c = *name++))
		hash = ((hash << 5) + hash) + c;
	return (hash % HASH_ROOMS);
}

void	create_keeper(t_room_keeper *k)
{
	if (!(k->n_hash = (t_room**)ft_memalloc(sizeof(t_room*) * HASH_ROOMS)))
		return ;
	k->room_counter = 3;
	if (!(k->coords = (int**)ft_memalloc(sizeof(int*) * 2)))
		return ;
	if (!(k->coords[0] = (int*)ft_memalloc(sizeof(int) * HASH_ROOMS)))
		return ;
	if (!(k->coords[1] = (int*)ft_memalloc(sizeof(int) * HASH_ROOMS)))
		return ;
	if (!(k->file = (char **)ft_memalloc(sizeof(char*) * 150000)))
		return ;
}

void	print_file(t_room_keeper *keeper)
{
	int i;

	i = 0;
	while (keeper->file[i] != NULL)
	{
		ft_printf("%s\n", keeper->file[i]);
		free(keeper->file[i]);
		i++;
	}
	free(keeper->file);
	ft_printf("\n");
}