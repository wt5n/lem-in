/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:03:01 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/17 17:14:51 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		length_of_path(t_room_keeper *keeper)
{
	int		length;
	t_room	*current;

	length = 0;
	current = keeper->n[2];
	while (current->prev_room != 0)
	{
		length++;
		current = keeper->n[current->prev_room];
	}
	return (length + 1);
}

void	mark_as_used(t_room_keeper *keeper, int to, int from)
{
	t_room	*room;
	int		i;

	i = 0;
	room = keeper->n[to];
	while ((from != room->links_id[0][i]) && (i < room->links_count))
		i++;
	room->links_id[1][i] = 1;
}

int		path_to_start(t_room_keeper *keeper, t_map_keeper *mp)
{
	int		from;
	int		length;
	t_map	*map;
	t_room	*room;

	length = length_of_path(keeper);
	map = create_map(length, mp->field);
	map->rooms[0] = 1;
	room = keeper->n[2];
	while (--length > 0)
	{
		map->rooms[length] = room->id;
		if (room->id == 1)
			break ;
		from = room->id;
		room = keeper->n[room->prev_room];
		mark_as_used(keeper, from, room->id);
		if (room->id != 2)
			room->visd = 1000000;
	}
	add_map_to_map_keeper(mp->rl, map);
	return (1);
}

int		path_to_finish(t_room_keeper *keeper, t_map_keeper *mp)
{
	t_queue	*queue;
	t_room	*current;

	if (!(queue = (t_queue*)ft_memalloc(sizeof(t_queue))))
		return (0);
	if (add_links_to_queue(keeper->n[1]->id, queue, keeper) == 1)
		return (path_to_start(keeper, mp));
	while (queue->stack != NULL)
	{
		current = keeper->n[out_queue(queue)];
		if (current->visd < keeper->v_limit)
		{
			current->visd = keeper->v_limit;
			if (add_links_to_queue(current->id, queue, keeper) == 1)
			{
				keeper->n[2]->prev_room = current->id;
				free_queue(queue);
				return (path_to_start(keeper, mp));
			}
		}
	}
	free_queue(queue);
	return (0);
}
