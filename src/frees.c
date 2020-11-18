/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:34:25 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/18 00:37:20 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	free_keeper(t_room_keeper *keeper)
{
	int	i;

	i = -1;
	while (++i < keeper->room_counter)
	{
		if (keeper->n[i] != NULL)
		{
			free(keeper->n[i]->name);
			free(keeper->n[i]->links_id[0]);
			free(keeper->n[i]->links_id[1]);
			free(keeper->n[i]->links_id);
			free(keeper->n[i]);
		}
	}
	free(keeper->coords[0]);
	free(keeper->coords[1]);
	free(keeper->coords);
	free(keeper->n_hash);
	free(keeper->n);
	free((keeper->bon));
	free(keeper);
}

void	free_queue(t_queue *queue)
{
	while (queue->stack != NULL)
		out_queue(queue);
	free(queue);
}

void	free_map(t_map *map)
{
	if (map != NULL)
	{
		free(map->rooms);
		if (map->queue != NULL)
			free_queue(map->queue);
		free(map);
	}
}

void	free_room_links(t_room_links *rl)
{
	t_room_links	*tmp;

	while (rl != NULL)
	{
		tmp = rl;
		rl = rl->next;
		free_map(tmp->data);
		free(tmp);
	}
	free(rl);
}

void	free_all(t_room_keeper *keeper, t_map_keeper *mp)
{
	free_keeper(keeper);
	free_room_links(mp->rl);
	free(mp);
}
