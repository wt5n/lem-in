#include "lem_in.h"

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

void clear_rooms(t_room_keeper *keeper)
{
	int i;
	int j;
	t_room *room;

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

void free_all()
{

};

void    ant_move(t_room_keeper *keeper, t_room_links *tmp, int inc_ant, int i)
{
    t_room  *cur;
    t_room  *prev;

    cur = keeper->n[tmp->data->rooms[i]];
    if (i == 1)
    {
	    if (i == tmp->data->length - 2)
	    {
		    if (cur->ant_num > 0)
		    {
			    tmp->data->ants_counter--;
			    keeper->finish->ant_num++;
				ft_printf("L%d-%s ", cur->ant_num, keeper->finish->name);
			}
		    cur->ant_num = 0;
	    }
        cur->ant_num = inc_ant;
        if (cur->ant_num > 0)
			ft_printf("L%d-%s ", inc_ant, cur->name);
    }
    else
    {
        if (i == tmp->data->length - 2)
        {
            if (cur->ant_num > 0)
            {
                tmp->data->ants_counter--;
                keeper->finish->ant_num++;
				ft_printf("L%d-%s ", cur->ant_num, keeper->finish->name);
			}
            cur->ant_num = 0;
        }
        if (i > 1)
		{
			prev = keeper->n[tmp->data->rooms[i - 1]];
			if (prev->ant_num != 0)
			{
				cur->ant_num = prev->ant_num;
				prev->ant_num = 0;
			}
		}
        if (cur->ant_num > 0)
			ft_printf("L%d-%s ", cur->ant_num, cur->name);
        ant_move(keeper, tmp, inc_ant, i - 1);
    }
}

int *check_paths(t_map_keeper *mp, int ants)
{
	t_room_links *tmp_links;
	int moves;
	int *res = (int *) ft_memalloc(sizeof(int) * 3);
	int path_counter = 0;

	moves = 0;
	tmp_links = mp->rl;
	while (tmp_links->data->field < mp->field)
		tmp_links = tmp_links->next;
	while (tmp_links != NULL && tmp_links->data->field == mp->field)
	{
		moves += tmp_links->data->length;
		path_counter++;
		tmp_links = tmp_links->next;
	}
	res[0] = ants / moves;
	res[1] = path_counter;
	res[2] = mp->field;
	return (res);
}

int *prepare_ants(t_room_keeper *keeper, t_map_keeper *mp, int field, int *oper)
{
	t_room_links *start;
	t_room_links *tmp;
	int ant_num;
	int ants = keeper->ants;

	ant_num = 0;
	start = mp->rl;
	if (start == NULL)
		return oper;
	while (start->data->field < field)
		start = start->next;
	while (ants--)
	{
		tmp = start;
		ant_num++;
		while (tmp->next != NULL && tmp->data->length + tmp->data->ants_counter >=
		                            tmp->next->data->length + tmp->next->data->ants_counter
		       && tmp->next->data->field == field)
			tmp = tmp->next;
		in_queue(tmp->data->queue, ant_num);
		tmp->data->ants_counter++;
	}
	if (oper[0] > start->data->ants_counter + start->data->length - 2)
	{
		oper[0] = start->data->ants_counter + start->data->length - 2;
		oper[1] = field;
	}
	return (oper);
}

void move_ants(t_room_keeper *keeper, t_map_keeper *mp, int field)
{
	int operation_count;
	t_room_links *start;
	t_room_links *tmp;

	operation_count = 0;
	start = mp->rl;
	while (start->data->field < field)
		start = start->next;
	while (keeper->finish->ant_num != keeper->ants)
	{
		tmp = start;
		while (tmp != NULL && tmp->data->field == field)
		{
			if (tmp->data->ants_counter > 0)
				ant_move(keeper, tmp, out_queue(tmp->data->queue), tmp->data->length - 2);
			tmp = tmp->next;
		}
		ft_printf("\n");
		operation_count++;
	}
	ft_printf("%d\n", operation_count);
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
//		if (min_field[2] % 100 == 0)
//			ft_printf("100 collisiy");
//		ft_printf("%d, %d, %d\n", min_field[0], min_field[1], min_field[2]);
//		break;
		if (min == k || delete_collisions(keeper) == 0)
			break;
		clear_rooms(keeper);
		keeper->n[1]->visited = 1000000;
		keeper->v_limit = 1;
		if (mp->field == 10)
			break;

		mp->field++;
		k = 0;
		i = 1;
	}
	move_ants(keeper, mp, best_field[1]);
//	ft_printf("");
//	ft_printf("");
//    while (mp->rl != NULL)
//    {
//    	while (mp->rl->data->field < min_field[2])
//    		mp->rl = mp->rl->next;
//    	while (mp->rl->data->queue->stack != NULL)
//    		ft_printf(" %d", out_queue(mp->rl->data->queue));
//    	ft_printf("\n");
//    	mp->rl = mp->rl->next;
//    }
//    solver(keeper, mp, min_field[2]);
//    free_all();
//    print_maps(mp);
}