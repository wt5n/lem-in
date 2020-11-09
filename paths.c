#include "lem_in.h"

int is_link_used (t_room *room, int target)
{
	int i;

	i = 0;
	if (room->id == 1)
		return (0);
	while (i < room->links_count)
	{
		// printf("i=%d [0][i]=%d\n", i, room->links_id[0][i]);
		if (room->links_id[0][i] == target)
		{
			if (room->links_id[1][i] == 1)
			{
				ft_printf ("the link is used\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int length_of_path (t_room_keeper *keeper)
{
	int length;
	t_room *current;

	length = 0;
	current = keeper->n[2];
	while (current->prev_room != 0)
	{
		length++;
		current = keeper->n[current->prev_room];
	}
	return (length + 1);
}

void mark_as_used (t_room_keeper *keeper, int to, int from)
{
	t_room *room;
	int i;

	i = 0;
	room = keeper->n[to];
	while ((from != room->links_id[0][i]) && (i < room->links_count))
		i++;
	room->links_id[1][i] = 1;

}

int path_to_start (t_room_keeper *keeper, t_map_keeper *mp)
{
	int from;
	int length;
	t_map *map;
	t_room *room;

	length = length_of_path (keeper);
	map = create_map (length, mp->field);
	map->rooms[0] = 1;
	room = keeper->n[2];
	while (--length > 0)
	{
		map->rooms[length] = room->id;
//		ft_printf("length=%d room=%s ", length, room->name);
		if (room->id == 1)
			break;
		from = room->id;
		room = keeper->n[room->prev_room];
		mark_as_used (keeper, from, room->id);
		if (room->id != 2)
			room->visited = 1;
		// print_all_links(room->name, room->links);
	}
//	ft_printf("\n");
	add_map_to_map_keeper (mp, map);
	return (1);
}

int path_to_finish (t_room_keeper *keeper, t_map_keeper *mp)
{
	int res;
	t_queue *queue;
	t_room *current;

	res = 0;
	queue = (t_queue *) ft_memalloc (sizeof (t_queue));
	if (add_links_to_queue (keeper->n[1]->id, queue, keeper) == 1)
	{
		res += path_to_start (keeper, mp);
		if (min_n (keeper->s_links, keeper->f_links) == res)
			return (res);
	}
	keeper->n[1]->visited = 1;
	while (queue->stack != NULL)
	{
		current = keeper->n[out_queue(queue)];
//        printf("current is %s\n", current->name);
		if (current->visited == 0)
		{
			current->visited = 1;
			if (add_links_to_queue (current->id, queue, keeper) == 1)
			{
				keeper->n[2]->prev_room = current->id;
				res += (path_to_start (keeper, mp));
				if (min_n (keeper->s_links, keeper->f_links) == res)
					return (res);
			}
		}
	}
	return (res);
}

int delete_collisions (t_room_keeper *keeper)
{
	int res;
	t_queue *queue;
	int num_of_links;
	t_room *room;
	t_room *linked_room;
	int i;
	res = 0;
	queue = (t_queue *)ft_memalloc(sizeof (t_queue));
	room = keeper->n[2];
	in_queue(queue, 2);
	num_of_links = room->links_count;
	while (queue != NULL)
	{
		room = keeper->n[out_queue(queue)];
		i = -1;
		while (++i < num_of_links)
		{
			linked_room = keeper->n[room->links_id[0][i]];
			if (room->links_id[0][i] != 0 && linked_room->links_id[1][i] 0)
				in_queue (queue, room->links_id[0][i]);
			if (room->links_id[1][i] == 1 && room->links_id[0][i] != (1 | 2))
			{
				res++;
				room->links_id[0][i] = 0;
				room->links_id[1][0] = 0;
			}
		}

	}
	return (0);
}