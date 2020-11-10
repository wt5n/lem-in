#include "lem_in.h"

t_map    *create_map(int length, int field)
{
	t_map 	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
    map->length = length;
	map->field = field;
	map->rooms = (int*)ft_memalloc(sizeof(int) * map->length);
    return (map);
}

void    add_map_to_map_keeper(t_room_links *rl, t_map *map)
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