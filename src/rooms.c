/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:10:06 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/17 17:14:51 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	add_next(t_room *master, t_room *slave)
{
	t_room	*tmp;

	tmp = master;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = slave;
}

int		find_room(t_room_keeper *keeper, int r, int find)
{
	t_room	*room;
	int		i;

	room = keeper->n[r];
	i = -1;
	while (++i < room->links_count)
		if (room->links_id[0][i] == find)
			return (i);
	return (-1);
}

t_room	*create_room(char *name, int id)
{
	t_room	*r;

	if (!(r = (t_room *)ft_memalloc(sizeof(t_room))))
		return (NULL);
	r->name = ft_strdup(name);
	r->id = id;
	r->links_count = NUM_LINKS;
	if (!(r->links_id = (int**)ft_memalloc(sizeof(int*) * 2)))
		return (NULL);
	if (!(r->links_id[0] = (int*)ft_memalloc(sizeof(int) * r->links_count)))
		return (NULL);
	if (!(r->links_id[1] = (int*)ft_memalloc(sizeof(int) * r->links_count)))
		return (NULL);
	return (r);
}

void	add_room(t_room_keeper *keeper, t_room *room)
{
	if (keeper->n_hash[get_hash((unsigned char*)room->name)])
		add_next(keeper->n_hash[get_hash((unsigned char*)room->name)], room);
	else
		keeper->n_hash[get_hash((unsigned char*)room->name)] = room;
}

void	clear_rooms(t_room_keeper *keeper)
{
	int		i;
	int		j;
	t_room	*room;

	i = 0;
	while (++i < keeper->room_counter)
	{
		j = -1;
		if (keeper->n[i] == 0)
			continue;
		room = keeper->n[i];
		room->visd = 0;
		room->prev_room = 0;
		room->in_q = 0;
		while (++j < room->links_count)
			room->links_id[1][j] = 0;
	}
	keeper->v_limit = 0;
}
