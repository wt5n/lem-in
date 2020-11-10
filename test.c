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

void    add_map_to_mk(t_room_links *links, t_map *map)
{
	t_room_links *tmp = (t_room_links *)ft_memalloc(sizeof (t_room_links));
	while (links->next)
		links = links->next;
	tmp->data = map;
	tmp->next = NULL;
	links->next = tmp;
}

void    print_maps(t_map_keeper *mp)
{
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

int main (void)
{
	t_map_keeper *mk = (t_map_keeper *)ft_memalloc(sizeof(t_map_keeper));
	mk->rl = (t_room_links *)ft_memalloc(sizeof(t_room_links));
	int ar[5] = {1, 3, 5, 6, 2};
	int ar2[4] = {1, 4, 7, 2};
	int ar3[7] = {1, 3, 4, 5, 6, 7, 2};
	t_map *map = create_m (5, 1);
	t_map *map2 = create_m (4, 1);
	t_map *map3 = create_m (7, 2);
	for (int i = 0; i < map->length; i++)
		map->rooms[i] = ar[i];
	for (int i = 0; i < map2->length; i++)
		map2->rooms[i] = ar2[i];
	for (int i = 0; i < map3->length; i++)
		map2->rooms[i] = ar3[i];
	add_map_to_mk(mk->rl, map);
	add_map_to_mk(mk->rl, map2);
	add_map_to_mk(mk->rl, map3);
	print_maps(mk);
	return (0);
} 