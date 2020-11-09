#include "lem_in.h"

int		is_link_used(t_room *room, int target)
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
            if (room->links_id[1][i] == 1) {
                ft_printf("the link is used\n");
                return (1);
            }
        }
        i++;
    }
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
	return (length + 1);
}

void	mark_as_used(t_room_keeper *keeper, int to, int from)
{
        t_room *room;
        int     i;

        i = 0;
        room = keeper->n[to];
        while ((from != room->links_id[0][i]) && (i < room->links_count))
            i++;
        room->links_id[1][i] = 1;

}

int 	path_to_start(t_room_keeper *keeper, t_map_keeper *mp)
{
	int 	from;
	int		length;
	t_map 	*map;
	t_room	*room;

    length = length_of_path(keeper);
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
		mark_as_used(keeper, from, room->id);
        if (room->id != 2)
            room->visited = 1000000;
		// print_all_links(room->name, room->links);
    }
	ft_printf("\n");
	add_map_to_map_keeper(mp, map);
    return (1);
}

int		path_to_finish(t_room_keeper *keeper, t_map_keeper *mp)
{
    t_queue			*queue;
    t_room 			*current;

    queue = (t_queue*)ft_memalloc(sizeof(t_queue));
    if (add_links_to_queue(keeper->n[1]->id, queue, keeper) == 1)
        return (path_to_start(keeper, mp));
    while (queue->stack != NULL)
    {
        current = keeper->n[out_queue(queue)];
        printf("current is %s\n", current->name);
        if (current->visited <= keeper->v_limit)
        {
            current->visited++;
            if (add_links_to_queue(current->id, queue, keeper) == 1)
            {
                keeper->n[2]->prev_room = current->id;
                return (path_to_start(keeper, mp));
            }
        }
    }
    return (0);
}

void    print_links(t_room_keeper *keeper, int id)
{
    t_room *room;
    int i;

    room = keeper->n[id];
    i = -1;
    printf("links of room %s\n", room->name);
    while (++i < room->links_count)
    {
        if (room->links_id[0][i] != 0 )
            printf("%d %d\n", room->links_id[0][i], room->links_id[1][i]);
    }
    printf("\n");
}

int    del_cols(t_room_keeper *keeper, int room, int linked_room, int num_lrm)
{
    t_room *rm;
    t_room *l_rm;

    int i = -1;
    rm = keeper->n[room];
    l_rm = keeper->n[linked_room];
    while (++i < rm->links_count)
    {
        if (rm->links_id[0][i] == linked_room && rm->links_id[1][i] != 1)
        {
            print_links(keeper, rm->id);
            print_links(keeper, l_rm->id);
            printf("%s rm->links_id[0][i] %d  ,%s l_rm->links_id[0][num_lrm] %d\n",
                rm->name, rm->links_id[0][i],
                l_rm->name, l_rm->links_id[0][num_lrm]);
            rm->links_id[0][i] = 0;
            l_rm->links_id[0][num_lrm] = 0;
            printf("collision is deleted\n");
            return (1);
        }
    }
    return (0);
}

int     find_room(t_room_keeper *keeper, int r, int find)
{
    t_room  *room;
    int     i;

    room = keeper->n[r];
    i = -1;
    while (++i< room->links_count)
        if (room->links_id[0][i] == find)
            return i;
    return (-1);
}

int     delete_collisions(t_room_keeper *keeper)
{
    t_queue *queue;
    t_room *room;
    t_room *linked_room;
    int i;
    int     tmp;

    queue = (t_queue *)ft_memalloc(sizeof (t_queue));
    in_queue(queue, 2);
    printf("Ya zdes' =)\n");
    while (queue->stack != NULL)
    {
        room = keeper->n[out_queue(queue)];
        i = -1;
        while (++i < room->links_count)
        {
            if (room->links_id[0][i] != 0)
                printf("%d\n", room->links_id[0][i]);
            if (room->visited < 1000001 && room->links_id[0][i] > 0)
            {
//                printf("room->links_id[0][i] %d\n", room->links_id[0][i]);
                linked_room = keeper->n[room->links_id[0][i]];
                tmp = find_room(keeper, linked_room->id, room->id);
                if (tmp == -1)
                    continue;
                if (linked_room->links_id[1][tmp] == 1)
                    if (del_cols(keeper, room->id, linked_room->id, i))
                        return (1);
                print_links(keeper, room->id);
                print_links(keeper, linked_room->id);
                if (room->links_id[1][i] != 1 && linked_room->visited < 1000001)
                    in_queue(queue, room->links_id[0][i]);
            }
        }
        room->visited = 1000001;
    }
    return (0);
}