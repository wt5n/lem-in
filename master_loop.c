#include "lem_in.h"

void    print_maps(t_map_keeper *mp)
{
    int     i;

    while (mp->rl != NULL)
    {
        i = 0;
        ft_printf("field is %d\n", mp->rl->data->field);
        while ((mp->rl->data->rooms[i] != 0) && (i < mp->rl->data->length))
        {
            ft_printf("%d ", mp->rl->data->rooms[i]);
            i++;
        }
        ft_printf("\n");
        mp->rl = mp->rl->next;
    }
}

void    clear_rooms(t_room_keeper *keeper)
{
    int     i;
    int     j;
    t_room  *room;

    i = 0;
    while (++i < keeper->RoomCounter)
    {
        j = -1;
        if (keeper->n[i] == 0)
            continue;
        room = keeper->n[i];
        room->visited = 0;
        room->prev_room = 0;
        room->in_q = 0;
        while (++j < room->links_count)
            room->links_id[1][j] = 0;
    }
    keeper->v_limit = 0;
}

void    free_all()
{

};

void	master_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
    int     i;

    i = 1;
    keeper->n[1]->visited = 1000000;
    while (1)
    {
        while (i != 0)
        {
            i = path_to_finish(keeper, mp);
            if (min_n(keeper->s_links, keeper->f_links) == i)
            {
                ft_printf("hvatit plz\n");
                break;
            }
            keeper->v_limit++;
        }
        if (delete_collisions(keeper) == 0)
            break;
        clear_rooms(keeper);
        keeper->n[1]->visited = 1000000;
        keeper->v_limit = 1;
        mp->field++;
        i = 1;
    }
    free_all();
    print_maps(mp);
}