/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:32:52 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/17 17:14:50 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	increase_links(t_room *room)
{
	int	**nl;
	int i;

	i = -1;
	if (!(nl = (int**)ft_memalloc((sizeof(int*) * 2))))
		return ;
	if (!(nl[0] = (int*)ft_memalloc((sizeof(int) * (room->links_count * 2)))))
		return ;
	if (!(nl[1] = (int*)ft_memalloc((sizeof(int) * (room->links_count * 2)))))
		return ;
	while (++i < room->links_count)
		nl[0][i] = room->links_id[0][i];
	free(room->links_id[0]);
	free(room->links_id[1]);
	free(room->links_id);
	room->links_id = nl;
	room->links_count = room->links_count * 2;
}

void	add_links(t_room *room, int link)
{
	int i;

	i = -1;
	while (++i < room->links_count)
	{
		if (room->links_id[0][i] == 0)
		{
			room->links_id[0][i] = link;
			return ;
		}
	}
	increase_links(room);
	add_links(room, link);
}

void	add_two_links(t_room *first, t_room *second)
{
	add_links(first, second->id);
	add_links(second, first->id);
}

int		finish_link(t_room_keeper *keeper, t_room *tmp_room, int i)
{
	int index;

	keeper->n[tmp_room->links_id[0][i]]->prev_room = tmp_room->id;
	keeper->n[tmp_room->links_id[0][i]]->in_q = keeper->v_limit;
	if (tmp_room->id == 1 && tmp_room->links_id[0][i] == 2)
	{
		tmp_room->links_id[0][i] = 0;
		tmp_room->links_id[1][i] = 0;
		index = find_room(keeper, 2, 1);
		keeper->n[2]->links_id[0][index] = 0;
		keeper->n[2]->links_id[1][index] = 0;
	}
	return (1);
}

int		add_links_to_queue(int id, t_queue *queue, t_room_keeper *keeper)
{
	t_room	*tmp_room;
	int		i;

	i = -1;
	tmp_room = keeper->n[id];
	while (++i < tmp_room->links_count)
	{
		if ((tmp_room->links_id[0][i] != 0) && (tmp_room->links_id[1][i] == 0))
		{
			if (tmp_room->links_id[0][i] == 2)
				return (finish_link(keeper, tmp_room, i));
			if (keeper->n[tmp_room->links_id[0][i]]->visd < keeper->v_limit &&
				keeper->n[tmp_room->links_id[0][i]]->in_q < keeper->v_limit)
			{
				keeper->n[tmp_room->links_id[0][i]]->prev_room = tmp_room->id;
				keeper->n[tmp_room->links_id[0][i]]->in_q = keeper->v_limit;
				in_queue(queue, tmp_room->links_id[0][i]);
			}
		}
	}
	return (0);
}
