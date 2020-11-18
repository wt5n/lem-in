/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:50:44 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/18 00:42:23 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_map		*create_map(int length, int field)
{
	t_map	*map;

	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->length = length;
	map->field = field;
	if (!(map->rooms = (int*)ft_memalloc(sizeof(int) * map->length)))
		return (NULL);
	if (!(map->queue = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	return (map);
}

void		add_map_to_map_keeper(t_room_links *rl, t_map *map)
{
	t_room_links	*tmp;

	if (rl->data == NULL)
		rl->data = map;
	else
	{
		if (!(tmp = (t_room_links*)ft_memalloc(sizeof(t_room_links))))
			return ;
		while (rl->next)
			rl = rl->next;
		tmp->data = map;
		tmp->next = NULL;
		rl->next = tmp;
	}
}

void		valid_room(t_room_keeper *keeper, t_room *room, char *name, int *xy)
{
	ft_strchr(name, ' ') ? ft_errors_lem_in(7) : 0;
	ft_strchr(name, '-') ? ft_errors_lem_in(7) : 0;
	if (keeper->s_c == 1)
		room = create_room(name, 1);
	else if (keeper->e_c == 1)
		room = create_room(name, 2);
	else
	{
		room = create_room(name, keeper->room_counter);
		keeper->room_counter++;
	}
	add_room(keeper, room);
	check_dup_name(keeper, name, room);
	check_dup_coor(keeper, room, xy);
	if (keeper->s_c == 1 || keeper->e_c == 1)
		start_end_rooms(keeper, room);
}

void		check_dup_name(t_room_keeper *keeper, char *name, t_room *room)
{
	int	i;

	i = 0;
	while (i < HASH_ROOMS)
	{
		if (keeper->names[i] != NULL)
			if (ft_strcmp(keeper->names[i], name) == 0)
				ft_errors_lem_in(8);
		i++;
	}
	keeper->names[room->id] = ft_strdup(name);
}
