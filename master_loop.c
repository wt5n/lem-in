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

int     ant_move(t_room_links *tmp, int ant_num)
{

}

void    solver(t_map_keeper *mp, t_room_keeper *keeper, int field)
{
	int ant_num;
	t_room_links *start;
	t_room_links *tmp;
	int i = 0;
	ant_num = 0;
	start = mp->rl;
	while (start->data->field < field)
		start = start->next;
	while (keeper->ants--)
	{
		i = 0;
		tmp = start;
		ant_num++;
		while (tmp->data->length + tmp->data->ants_counter >
		tmp->next->data->length + tmp->next->data->ants_counter && tmp->next != NULL)
			tmp = tmp->next;
		tmp->data->ants_counter++;
		if (keeper->n[tmp->data->rooms[i]]->ant_num > 0)

			i++;
		ant_num++;
	}
}

int     *check_paths(t_map_keeper *mp, int ants)
{
	t_room_links *tmp_links;
	int moves;
	int *res = (int *)ft_memalloc(sizeof(int) * 3);
	int room_counter = 0;

	moves = 0;
	tmp_links = mp->rl;
	while (tmp_links->data->field < mp->field)
		tmp_links = tmp_links->next;
	while (tmp_links != NULL && tmp_links->data->field == mp->field)
	{
		moves += tmp_links->data->length;
		room_counter++;
		tmp_links = tmp_links->next;
	}
	res[0] = ants / moves;
	res[1] = room_counter;
	res[2] = mp->field;
	return (res);
}

void    solve(t_room_keeper *keeper, t_map_keeper *mp);

void	master_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
    int     i;
    int     k;
    int     *best_field;
	int     min;
	int     min_field[3];

	min_field[0] = MAXINT;
	min_field[1] = 0;
	min_field[2] = 0;
    i = 1;
    k = 0;
    min = min_n(keeper->s_links, keeper->f_links);
    keeper->n[1]->visited = 1000000;
    while (1)
    {
        while (i != 0)
        {
            i = path_to_finish(keeper, mp);
            k += i;
            if (min == k)
            {
                ft_printf("hvatit plz\n");
                break;
            }
            keeper->v_limit++;
        }
        best_field = check_paths(mp, keeper->ants);
        if (best_field[0] < min_field[0] && best_field[1] >= min_field[1])
        {
	        min_field[0] = best_field[0];
	        min_field[1] = best_field[1];
	        min_field[2] = best_field[2];
        }
        printf("%d, %d, %d\n", min_field[0], min_field[1], min_field[2]);
        if (min == k || delete_collisions(keeper) == 0)
            break;
        clear_rooms(keeper);
        keeper->n[1]->visited = 1000000;
        keeper->v_limit = 1;
        if (mp->field == 20)
	        break ;
        mp->field++;
        k = 0;
        i = 1;
    }
    free_all();
    print_maps(mp);
}