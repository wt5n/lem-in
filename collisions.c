# include "lem_in.h"

int    del_cols(t_room_keeper *keeper, int room, int linked_room, int num_lrm)
{
    t_room *rm;
    t_room *l_rm;

    int i = -1;
    rm = keeper->n[room];
    l_rm = keeper->n[linked_room];
    while (++i < rm->links_count)
    {
        if (rm->links_id[0][i] == linked_room && rm->links_id[1][i] != 1 &&
			(room != 1 && room != 2) && (linked_room != 1 && linked_room != 2))
        {
            // print_links(keeper, rm->id);
            // print_links(keeper, l_rm->id);
//            ft_printf("%s rm->links_id[0][i] %d  ,%s l_rm->links_id[0][num_lrm] %d\n",
//                rm->name, rm->links_id[0][i],
//                l_rm->name, l_rm->links_id[0][num_lrm]);
            rm->links_id[0][i] = 0;
            l_rm->links_id[0][num_lrm] = 0;
//            ft_printf("collision is deleted\n");
            return (1);
        }
    }
    return (0);
}

int     find_room(t_room_keeper *keeper, int r, int find)
{
    t_room  *room;
    int     i;

    //  print_links(keeper, r);
    //  print_links(keeper, find);
    room = keeper->n[r];
    i = -1;
    while (++i< room->links_count)
        if (room->links_id[0][i] == find)
            return (i);
    return (-1);
}

int     delete_collisions(t_room_keeper *keeper)
{
    t_queue *queue;
    t_room *room;
    t_room *linked_room;
    int i;
    int     tmp;

    if (!(queue = (t_queue *)ft_memalloc(sizeof (t_queue))))
        return (NULL);
    in_queue(queue, 2);
    while (queue->stack != NULL)
    {
        room = keeper->n[out_queue(queue)];
        i = -1;
        while (++i < room->links_count)
        {
            if (room->visited < 1000001 && room->links_id[0][i] > 0)
            {
                linked_room = keeper->n[room->links_id[0][i]];
                tmp = find_room(keeper, linked_room->id, room->id);
                if (tmp == -1)
                    continue;
                if (linked_room->links_id[1][tmp] == 1)
                    if (del_cols(keeper, room->id, linked_room->id, tmp))
                        return (1);
                if (room->links_id[1][i] != 1 && linked_room->visited < 1000001)
                    in_queue(queue, room->links_id[0][i]);
            }
        }
        room->visited = 1000001;
    }
    return (0);
}