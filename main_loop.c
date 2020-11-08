#include "lem_in.h"




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

void    clear_rooms(t_room_keeper *keeper)
{
    int     i;
    int     j;
    t_room  *room;

    i = 2;
    while (++i < keeper->RoomCounter)
    {
        j = -1;
        room = keeper->n[i];
        room->visited = 0;
        room->prev_room = 0;
        while (j++ < room->links_count)
            room->links_id[1][j] = 0;
    }
}

void    free_all()
{

};

void	main_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
    int             i;

    i = 1;
	while (1)
	{
        i = path_to_finish(keeper, mp);
        if (min_n(keeper->s_links, keeper->f_links) == i)
            pritnf("hvatit plz\n");
        if (i != 0)
            if (delete_collisions(keeper, mp) == 0)
                break;;
        clear_rooms(keeper);
        mp->field++;
    }
    free_all();
    print_maps(mp, keeper);
    // if ((delete_collisions(keeper, mp)) == 1)
	// {
	// 	mp->field++;
	// 	main_loop(keeper, mp);
	// }
}