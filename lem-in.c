#include "lem_in.h"


unsigned long get_hash(unsigned char *name)
{
    unsigned long hash = VALUE_HASH_ROOMS;
    int c;

    while ((c = *name++))
        hash = ((hash << 5) + hash) + c;

    return (hash % VALUE_HASH_ROOMS);
}

void		find_count_s_f(t_room_keeper *keeper)
{
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

void master_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
    int i;
    int k;
    int *best_field;
    int min;
    int iii;

    iii = 0;
    if (!(best_field = (int *)ft_memalloc(sizeof(int) * 3)))
        return ;
    best_field[0] = MAXINT;
    best_field[1] = 0;
    i = 1;
    k = 0;
    min = min_n(keeper->s_links, keeper->f_links);
    keeper->n[1]->visited = 1000000;
    if (find_room(keeper, 1, 2) >= 0)
    {
        while (++iii < keeper->ants + 1)
            ft_printf("L%d-%s ", iii ,keeper->finish->name);
        exit(1);
    }
    while (1)
    {
        while (i != 0)
        {
            i = path_to_finish(keeper, mp);
            k += i;
            if (min == k)
                break;
            keeper->v_limit++;
        }
        best_field = prepare_ants(keeper, mp, mp->field, best_field);
        if (min == k || delete_collisions(keeper) == 0)
            break;
        clear_rooms(keeper);
        keeper->n[1]->visited = 1000000;
        keeper->v_limit = 1;
        if (mp->field == 5)
            break;
        mp->field++;
        k = 0;
        i = 1;
    }
    move_ants(keeper, mp, best_field[1]);
    free(best_field);
//    while (mp->rl != NULL)
//    {
//    	while (mp->rl->data->field < min_field[2])
//    		mp->rl = mp->rl->next;
//    	while (mp->rl->data->queue->stack != NULL)
//    		ft_printf(" %d", out_queue(mp->rl->data->queue));
//    	ft_printf("\n");
//    	mp->rl = mp->rl->next;
//    }
//    free_all();
}

int		main(void)
{
	t_room_keeper *keeper;
    t_map_keeper *mp;

    if (!(keeper = (t_room_keeper*)ft_memalloc(sizeof(t_room_keeper))))
        return 0;
    if (!(keeper->n_hash = (t_room**)ft_memalloc(sizeof(t_room*) * VALUE_HASH_ROOMS)))
        return 0;
    keeper->roomCounter = 3;
    parse_input(keeper);
    if (!(keeper->n = (t_room**)ft_memalloc(sizeof(t_room*) * keeper->roomCounter)))
        return 0;
    keeper->v_limit = 1;
    pass_to_n(keeper);
    if (!(mp = (t_map_keeper*)ft_memalloc(sizeof(t_map_keeper))))
        return 0;
    mp->field = 1;
    if (!(mp->rl = (t_room_links*)ft_memalloc(sizeof(t_room_links))))
        return 0;
    find_count_s_f(keeper);
    keeper->start->ant_num = keeper->ants;
    master_loop(keeper, mp);
    free_all(keeper, mp);
	return (1);
}