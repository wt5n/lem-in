#include "lem_in.h"

// poisk puti

int	is_link_used(t_room *room, char *target)
{
	return (0);
}

int	path_to_finish(t_room_keeper *keeper, t_room_keeper *c_k1, t_map_keeper *map_keeper)
{
	char *prev;
	t_queue			*queue;
	t_room_keeper	*c_k2;
	t_room *current;

	c_k2 = c_k1;
	queue = (t_queue*)malloc(sizeof(t_queue));
	queue->stack = NULL;
	if (add_links_to_queue(c_k2->start, queue, c_keeper) == 1)
	{
		keeper->finish->prev_room = keeper->start->name;
		path_to_start();
	}
	{
		prev = c_k2->start->name;
		while (queue->stack != NULL)
		{
			current = c_k2->n[get_hash(out_queue(queue))];
			printf("%s\n", current->name);
			if (current->visited == 0)
			{
				current->visited = 1;
				add_tmp_prev_room(current, prev);
				if (add_links_to_queue(current, queue, keeper) == 1)
				{
					keeper->finish->prev_room = current->name;
					path_to_start();
				}
			}
			prev = current->name;
		}
	}
	return (0);
}

int		length_of_path(t_room_keeper *keeper)
{
	int		length;
	t_room	*current;

	length = 0;
	current = keeper->finish;
	while (current->tmp_prev_room != NULL)
	{
		length++;
		current = keeper->n[get_hash(current->tmp_prev_room)];
	}
	return (length);
}

void	mark_as_used(t_room_keeper *c_k1, char *room, char *link)
{
	t_room *r;

	r = c_k1->n[get_hash(r->name)];
	while (ft_strcmp(r->links->name, link) != 0)
	{
		r->links = r->links->next;
	}
	r->links->used = 1;
}

void	path_to_start(t_room_keeper *c_k1, t_room_keeper *c_k2, t_map_keeper *mp)
{
	char 	*from;
	int		length;
	t_map 	*map;
	t_room	*room;

	map->length = length_of_path();
	map->field = mp->field;
	map->rooms = (char**)malloc(sizeof(char*) * map->length);
	length--;
	room = c_k2->finish;
	while (length > 0)
	{
		map->rooms[length] = ft_strcpy_wm(room->name);
		from = room->name;
		room = c_k2->n[get_hash(room->prev_room)];
		mark_as_used(c_k1, room->name, from);
		length--;
	}
	add_map_to_map_keeper(mp, map);
}