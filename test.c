#include "lem_in.h"

t_map    *create_m(int length, int field)
{
	t_map 	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->length = length;
	map->field = field;
	map->rooms = (int*)ft_memalloc(sizeof(int) * map->length);
	return (map);
}

int     find_room(t_room_keeper *keeper, int r, int find)
{
	t_room  *room;
	int     i;

	//  print_links(keeper, r);
	//  print_links(keeper, find);
	room = keeper->n[r];
	i = -1;
	while (++i< room->links_count)
		if (room->links_id[0][i] == find)
			return (i);
	return (-1);
}

void    add_map_to_mk(t_room_links *rl, t_map *map)
{
	t_room_links *tmp = (t_room_links *)ft_memalloc(sizeof (t_room_links));

	if (rl->data == NULL)
		rl->data = map;
	else
	{
		while (rl->next)
			rl = rl->next;
		tmp->data = map;
		tmp->next = NULL;
		rl->next = tmp;
	}
}

void    print_m(t_map_keeper *mp)
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

int     *check_paths(t_map_keeper *mp)
{
	t_room_links *tmp_links;
	int moves;
	int ants = mp->ants;
	int *res = (int *)ft_memalloc(sizeof(int) * 2);
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
	return (res);
}



int main (void)
{
	t_map_keeper *mk = (t_map_keeper *)ft_memalloc(sizeof(t_map_keeper));
	mk->rl = (t_room_links *)ft_memalloc(sizeof(t_room_links));
	mk->ants = 100;
	int *best;
	int ar[5] = {1, 3, 5, 6, 2};
	int ar2[4] = {22, 44, 77, 33};
	int ar3[7] = {333, 334, 401, 506, 643, 778, 299};
	t_map *map = create_m (5, 1);
	t_map *map2 = create_m (4, 1);
	t_map *map3 = create_m (7, 2);
	for (int i = 0; i < map->length; i++)
		map->rooms[i] = ar[i];
	for (int i = 0; i < map2->length; i++)
		map2->rooms[i] = ar2[i];
	for (int i = 0; i < map3->length; i++)
		map3->rooms[i] = ar3[i];
    add_map_to_mk(mk->rl, map);
	add_map_to_mk(mk->rl, map2);
	add_map_to_mk(mk->rl, map3);
	mk->field = 1;
	best = check_paths(mk);
	printf("%d  %d\n", best[0], best[1]);
	mk->field = 2;
	best = check_paths(mk);
	printf("%d  %d\n", best[0], best[1]);
//	print_m(mk);
	return (0);
}