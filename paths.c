#include "lem_in.h"

void    add_map_to_map_keeper(t_map_keeper *mp, t_map *map)
{
    return ;
}

int		is_link_used(t_room *room, char *target)
{
	return (0);
}

int		length_of_path(t_room_keeper *c_k2)
{
	int		length;
	t_room	*current;

	length = 0;
	current = c_k2->finish;
	while (current->prev_room != NULL)
	{
		length++;
		current = c_k2->n[get_hash(current->prev_room)];
	}
	return (length);
}

void	mark_as_used(t_room_keeper *c_k1, t_room_keeper *c_k2, t_room *room, char *link)
{
	t_room *r;

    print_all_links(c_k2->n[get_hash("F")]);
//    r = c_k1->n[get_hash(room)];
    r = room;
	ft_printf("links->name %s\n", room->links->name);
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

//	print_all_links(c_k2->n[get_hash("F")]);
    length = length_of_path(c_k2);
	map->length = length;
	map->field = mp->field;
	map->rooms = (char**)malloc(sizeof(char*) * map->length);
	length--;
	room = c_k2->finish;
	while (length > 0)
	{
		map->rooms[length] = ft_strcpy_wm(room->name);
		from = room->name;
		room = c_k2->n[get_hash(room->prev_room)];
//		mark_as_used(c_k1, c_k2, room, from);
		length--;
	}
	add_map_to_map_keeper(mp, map);
}

int		path_to_finish(t_room_keeper *c_k1, t_map_keeper *mp)
{
//    char 			*prev;
    t_queue			*queue;
    t_room_keeper	*c_k2;
    t_room 			*current;

    c_k2 = c_k1;
    queue = (t_queue*)malloc(sizeof(t_queue));
    queue->stack = NULL;
    if (add_links_to_queue(c_k2->start, queue, c_k2) == 1)
    {
//        c_k2->finish->prev_room = c_k2->start->name;
        path_to_start(c_k1, c_k2, mp);
        return (1);
    }
//    prev = c_k2->start->name;
    while (queue->stack != NULL)
    {
        current = c_k2->n[get_hash(out_queue(queue))];
        printf("current is %s\n", current->name);
        if (ft_strcmp(current->name, "F") == 0)
            ft_printf("\n");
        if (current->visited == 0)
        {
            current->visited = 1;
//            add_prev_room(current, prev);
            if (add_links_to_queue(current, queue, c_k2) == 1)
            {
                c_k2->finish->prev_room = current->name;
                path_to_start(c_k1, c_k2, mp);
                return (1);
            }
        }
//        prev = current->name;
    }
    return (0);
}