#include "lem_in.h"

void    add_map_to_map_keeper(t_map_keeper *mp, t_map *map)
{
    t_map  *tmp_map;

    tmp_map = mp->next;
    if (tmp_map != NULL)
    {
        tmp_map = mp->next;
        mp->next = tmp_map;
    }
    map->next = NULL;
    mp->next = map;
}

int		is_link_used(t_room *room, char *target)
{
	return (0);
}

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
	return (length);
}

void	mark_as_used(t_room_keeper *c_k1, t_room_keeper *c_k2, t_link *links, char *link)
{
	t_link *r;

//    r = c_k2->n[get_hash("F")];
//    print_all_links(r->links);
//    r = c_k1->n[get_hash(room)];
    r = links;
	while (ft_strcmp(r->name, link) != 0)
	{
		r = r->next;
	}
//    ft_printf("links->name %s\n", r->name);
    r->used = 1;
}

t_map    *create_map(int length, int field)
{
	t_map 	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
    map->length = length;
	map->field = field;
	map->rooms = (int*)malloc(sizeof(int) * map->length);
    return (map);
}

void	path_to_start(t_room_keeper *keeper, t_map_keeper *mp)
{
	int 	from;
	int		length;
	t_map 	*map;
	t_room	*room;

    length = length_of_path(keeper) + 1;
    map = create_map(length, mp->field);
    map->rooms[0] = 1;
    room = keeper->n[2];
	while (--length > 0)
	{
		map->rooms[length] = room->id;
		ft_printf("length=%d room=%s ", length, room->name);
        if (room->id == 1)
            break;
		from = room->id;
		room = keeper->n[room->prev_room];
		// mark_as_used(c_k1, c_k2, room->links, from);
		// print_all_links(room->name, room->links);
    }
	ft_printf("\n");
	add_map_to_map_keeper(mp, map);
}

int		path_to_finish(t_room_keeper *keeper, t_map_keeper *mp)
{
//    char 			*prev;
    t_queue			*queue;
    t_room 			*current;

    queue = (t_queue*)ft_memalloc(sizeof(t_queue));
    if (add_links_to_queue(keeper->n[1]->id, queue, keeper) == 1)
    {
//        c_k2->finish->prev_room = c_k2->start->name;
        path_to_start(keeper, mp);
        return (1);
    }
    keeper->n[1]->visited = 1;
//    prev = c_k2->start->name;
    while (queue->stack != NULL)
    {
        current = keeper->n[out_queue(queue)];
        printf("current is %s\n", current->name);
        if (current->visited == 0)
        {
            current->visited = 1;
//            add_prev_room(current, prev);
            if (add_links_to_queue(current->id, queue, keeper) == 1)
            {
                keeper->n[2]->prev_room = current->id;
                path_to_start(keeper, mp);
                return (1);
            }
        }
//        prev = current->name;
    }
    return (0);
}