#include "lem_in.h"

t_map    *create_map(int length, int field)
{
	t_map 	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
    map->length = length;
	map->field = field;
	map->rooms = (int*)malloc(sizeof(int) * map->length);
    return (map);
}

void    add_map_to_map_keeper(t_map_keeper *mp, t_map *map)
{
    t_room_links *tmp_link;
    t_room_links *t;

    t = (t_room_links*)malloc(sizeof(t_room_links));
    t->data = NULL;
    t->next = NULL;
    tmp_link = (t_room_links*)malloc(sizeof(t_room_links));
    tmp_link->data = map;
    tmp_link->next = NULL;

    if (mp->rl->data == NULL)
    {
        mp->rl = tmp_link;
        // mp->rl->next = tmp_link;
        return ;
    }
    t->next = mp->rl->next;
    while (t->next != NULL)
    {
        t->data = t->next->data;
    }
    t = tmp_link;
    mp->rl->next = t;
}