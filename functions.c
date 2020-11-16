#include "lem_in.h"

void    print_links(t_room_keeper *keeper, int id)
{
    t_room *room;
    int i;

    room = keeper->n[id];
    i = -1;
    ft_printf("links of room %s\n", room->name);
    while (++i < room->links_count)
    {
        if (room->links_id[0][i] != 0 )
            ft_printf("%d %d\n", room->links_id[0][i], room->links_id[1][i]);
    }
    ft_printf("\n");
}

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
//                ft_printf("the link is used\n");
                return (1);
            }
        }
        i++;
    }
    return (0);
}

void print_maps(t_map_keeper *mp)
{
    int i;

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

void        print_keeper_rooms(t_room_keeper *keeper)
{
    int i;

    i = -1;
    ft_printf("room_counter %d\n", keeper->room_counter);
    while (++i < keeper->room_counter)
        ft_printf("%d\n", keeper->n[i]->id);
}