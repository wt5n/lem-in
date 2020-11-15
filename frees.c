/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:34:25 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/15 16:04:15 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_room(t_room *room)
{
	free(room->name);
	free(room->links_id[0]);
	free(room->links_id[1]);
	free(room->links_id);
	free(room);
}

void	free_keeper(t_room_keeper *keeper)
{
	int	i;

	i = -1;
	while (++i < keeper->roomCounter)
	{
		if (keeper->n[i] != NULL)
			free_room(keeper->n[i]);
	}
	free(keeper->n_hash);
	free(keeper->n);
	free(keeper);
}

//void	free_list_queue(t_list_queue *queue)
//{
//	if (queue->next != NULL)
//		free_list_queue(queue->next);
//	free(queue);
//}

void 	free_queue(t_queue *queue)
{
	while (queue->stack != NULL)
		out_queue(queue);
	free(queue);
}

void	free_map(t_map *map)
{
	free(map->rooms);
	if (map->queue != NULL)
		free_queue(map->queue);
	free(map);
}

void 	free_room_links(t_room_links *rl)
{
	t_room_links  *tmp;

	while (rl != NULL)
	{
		tmp = rl;
		rl = rl->next;
		free_map(tmp->data);
		free(tmp);
	}
	free(rl);
}

void	free_mp(t_map_keeper *mp)
{
	free_room_links(mp->rl);
//	free(mp->rl);
	free(mp);
}

void	free_all(t_room_keeper * keeper, t_map_keeper *mp)
{
	free_keeper(keeper);
	free_mp(mp);
}