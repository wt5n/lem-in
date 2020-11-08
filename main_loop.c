#include "lem_in.h"


int		delete_collisions(t_room_keeper *c_k1, t_map_keeper *keeper)
{
	return (0);
}

void    print_maps(t_map_keeper *mp, t_room_keeper *keeper)
{
    t_map   *tmp_map;
    t_room *tmp_room;
    int     *tmp_id;
    int     i;

    while (mp->rl != NULL)
    {
        i = 0;
        while ((mp->rl->data->rooms[i] != 0) && (i < mp->rl->data->length))
        {
            ft_printf("%d ", mp->rl->data->rooms[i]);
            i++;
        }
        ft_printf("\n");
        mp->rl = mp->rl->next;
    }
}

void    clear_rooms(t_room_keeper *keeper, int all)
{
    int     i;
    int     j;
    t_room  *room;

    i = 2;
    while (++i < keeper->RoomCounter)
    {
        j = -1;
        room = keeper->n[i];
        if (room->visited == 1)
            room->visited = 0;
        room->prev_room = 0;
        if (all == 1)
        {
            room->visited = 0;
            while (j++ < room->links_count)
                room->links_id[1][j] = 0;

        }
    }
}

void	main_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
    int             i;

    i = 1;
	while (1 == 1)
	{
        i = path_to_finish(keeper, mp);
        if (i == -1)
            break;
        clear_rooms(keeper, i);
        if (i == 1)
            mp->field++;
    }
    print_maps(mp, keeper);
    // if ((delete_collisions(keeper, mp)) == 1)
	// {
	// 	mp->field++;
	// 	main_loop(keeper, mp);
	// }
}