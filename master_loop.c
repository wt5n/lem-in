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

void     ant_move(t_room_keeper *keeper, t_room_links *tmp, int inc_ant, int i)
{
    int throw_ant;

	ft_printf("id = %d, ant_num =%d\n", keeper->n[tmp->data->rooms[i]]->id, keeper->n[tmp->data->rooms[i]]->ant_num);
    if (tmp->data->rooms[i] == 2)
    {
	    ft_printf("id = %d, ant_num =%d\n", keeper->n[tmp->data->rooms[i]]->id, keeper->n[tmp->data->rooms[i]]->ant_num);
	    tmp->data->ants_counter--;
	    keeper->finish->ant_num++;
    }
    else if (keeper->n[tmp->data->rooms[i]]->ant_num > 0)
    {
	    ft_printf("id = %d, ant_num =%d\n", keeper->n[tmp->data->rooms[i]]->id, keeper->n[tmp->data->rooms[i]]->ant_num);
        throw_ant = keeper->n[tmp->data->rooms[i]]->ant_num;
        keeper->n[tmp->data->rooms[i]]->ant_num = inc_ant;
	    ft_printf("id = %d, ant_num =%d\n", keeper->n[tmp->data->rooms[i]]->id, keeper->n[tmp->data->rooms[i]]->ant_num);
        ant_move(keeper, tmp, throw_ant, i + 1);
    }
    else
    {
        keeper->n[tmp->data->rooms[i]]->ant_num = inc_ant;
	    ft_printf("id = %d, ant_num =%d\n", keeper->n[tmp->data->rooms[i]]->id, keeper->n[tmp->data->rooms[i]]->ant_num);
        tmp->data->ants_counter++;
    }
}

void     ant_move_2(t_room_keeper *keeper, t_room_links *tmp, int inc_ant, int i)
{
    int throw_ant;

    if (tmp->data->rooms[i] == 2)
    {
	    tmp->data->ants_counter--;
	    keeper->finish->ant_num++;
    }
    else if (keeper->n[tmp->data->rooms[i]]->ant_num > 0)
    {
        throw_ant = keeper->n[tmp->data->rooms[i]]->ant_num;
        keeper->n[tmp->data->rooms[i]]->ant_num = 0;
        ant_move(keeper, tmp, throw_ant, i + 1);
    }
    else
        ant_move(keeper, tmp, 0, i + 1);
}

void    ant_goto_finish(t_room_keeper *keeper, t_map_keeper *mp, int field, t_room_links *start)
{
    t_room_links *tmp;

    tmp = start;
	while (keeper->ants != keeper->finish->ant_num)
	{
		if (tmp == NULL)
			tmp = start;
		if (tmp->data->ants_counter != 0)
			ant_move_2(keeper, tmp, 0, 0);
		tmp = tmp->next;
	}
}

void    solver(t_room_keeper *keeper, t_map_keeper *mp, int field)
{
	int ant_num;
	t_room_links *start;
	t_room_links *tmp;

	ant_num = 0;
	start = mp->rl;
	while (start->data->field < field)
		start = start->next;
	while (keeper->start->ant_num--)
	{
		tmp = start;
		ant_num++;
		while (tmp->next != NULL && tmp->data->length + tmp->data->ants_counter >
		    tmp->next->data->length + tmp->next->data->ants_counter)
			tmp = tmp->next;
		ant_move(keeper, tmp, ant_num, 1);
	}
    ant_goto_finish(keeper, mp, field, start);
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

void    prepare_ants(t_room_keeper *keeper, t_map_keeper *mp, int field)
{
	t_room_links *start;
	t_room_links *tmp;
	int ant_num;

	ant_num = 0;
	start = mp->rl;
	while (start->data->field < field)
		start = start->next;
	while (keeper->start->ant_num--)
	{
		tmp = start;
		ant_num++;
		while (tmp->next != NULL && tmp->data->length + tmp->data->ants_counter >
		                            tmp->next->data->length + tmp->next->data->ants_counter)
			tmp = tmp->next;
		in_queue(tmp->data->queue, ant_num);
		tmp->data->ants_counter++;
	}
}

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
        ft_printf("%d, %d, %d\n", min_field[0], min_field[1], min_field[2]);
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
	prepare_ants(keeper, mp, min_field[2]);
    solver(keeper, mp, min_field[2]);
//    free_all();
//    print_maps(mp);
}