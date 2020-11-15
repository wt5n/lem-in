#include "lem_in.h"

t_map    *create_map(int length, int field)
{
	t_map 	*map;

	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		return (NULL);
    map->length = length;
	map->field = field;
	if (!(map->rooms = (int*)ft_memalloc(sizeof(int) * map->length)))
		return NULL;
	if (!(map->queue = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (NULL);
    return (map);
}

void    add_map_to_map_keeper(t_room_links *rl, t_map *map)
{
	t_room_links *tmp;


	if (rl->data == NULL)
	    rl->data = map;
	else
	{
		if (!(tmp = (t_room_links*)ft_memalloc(sizeof(t_room_links))))
			return ;
		while (rl->next)
			rl = rl->next;
		tmp->data = map;
		tmp->next = NULL;
		rl->next = tmp;
	}
}