#include "lem_in.h"

void        print_keeper_rooms(t_room_keeper *keeper)
{
    int i;

    i = -1;
    ft_printf("RoomCounter %d\n", keeper->RoomCounter);
    while (++i < keeper->RoomCounter)
        ft_printf("%d\n", keeper->n[i]->id);
}


void		find_count_s_f(t_room_keeper *keeper)
{
	t_room 	room;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < keeper->n[1]->links_count)
		if (keeper->n[1]->links_id[0][i] != 0)
			j++;
	keeper->s_links = j;
	j = 0;
	i = -1;
	while (++i < keeper->n[2]->links_count)
		if (keeper->n[2]->links_id[0][i] != 0)
			j++;
	keeper->f_links = j;
}

int		main(void)
{
	t_room_keeper *keeper = (t_room_keeper*)ft_memalloc(sizeof(t_room_keeper));
	keeper->n_hash = (t_room**)ft_memalloc(sizeof(t_room*) * 3000);
	keeper->RoomCounter = 3;
	parse_input(keeper);
    keeper->n = (t_room**)ft_memalloc(sizeof(t_room*) * keeper->RoomCounter);
	keeper->v_limit = 1;
	pass_to_n(keeper);

	t_map_keeper *mp;
	mp = (t_map_keeper*)ft_memalloc(sizeof(t_map_keeper));
	mp->field = 1;
	mp->rl = (t_room_links*)ft_memalloc(sizeof(t_room_links));
	find_count_s_f(keeper);
	keeper->start->ant_num = keeper->ants;
    master_loop(keeper, mp);
	ft_printf("finish\n");
	return (1);
}