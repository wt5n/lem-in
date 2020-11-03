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

    i = 0;
    tmp_map = (t_map*)malloc(sizeof(t_map));
    tmp_map = mp->next;
    while (tmp_map != NULL)
    {

        tmp_id = tmp_map->rooms;
        while (i < tmp_map->length)
        {
            tmp_room = keeper->n[tmp_id[i]];
            ft_printf("%s(%d) - ", tmp_room->name, tmp_room->id);
            i++;
        }
        ft_printf("\n");
        tmp_map = mp->next;
    }


}

void	main_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
    int             i;

    i = 1;
	while (i != 0)
	{
        i = path_to_finish(keeper, mp);
        print_maps(mp, keeper);
    }
	if ((delete_collisions(keeper, mp)) == 1)
	{
		mp->field++;
		main_loop(keeper, mp);
	}
}