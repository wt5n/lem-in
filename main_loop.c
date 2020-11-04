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


//    tmp_map = mp->rl->next;
//    while (tmp_map != NULL)
//    {
//
//        tmp_id = tmp_map->rooms;
//        while (i < tmp_map->length)
//        {
//            tmp_room = keeper->n[tmp_id[i]];
//            ft_printf("%s(%d) - ", tmp_room->name, tmp_room->id);
//            i++;
//        }
//        ft_printf("\n");
//        tmp_map = mp->rl->next;
//    }
}

void    clear_rooms(t_room_keeper *keeper)
{
    int i;
    t_room  *room;

    i = 2;
    while (++i < keeper->RoomCounter)
    {
        room = keeper->n[i];
        room->visited = 0;
    }
}

void	main_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
    int             i;

    i = 1;
	while (i != 0)
	{
        i = path_to_finish(keeper, mp);
        clear_rooms(keeper);
    }
    print_maps(mp, keeper);
    // if ((delete_collisions(keeper, mp)) == 1)
	// {
	// 	mp->field++;
	// 	main_loop(keeper, mp);
	// }
}