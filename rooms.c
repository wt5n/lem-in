#include "lem_in.h"

t_room *create_room(char *name, int id)
{
	t_room *room ;

	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		return (NULL);

	room->name = ft_strcpy_wm(name);
	room->id = id;
	room->links_count = NUM_LINKS;
	if (!(room->links_id = (int**)ft_memalloc(sizeof(int*) * 2)) ||
		!(room->links_id[0] = (int*)ft_memalloc(sizeof(int) * room->links_count)) ||
		!(room->links_id[1] = (int*)ft_memalloc(sizeof(int) * room->links_count)))
		return NULL;
	room->ishash = get_hash(name);
	return room;
}

void	add_prev_room(t_room_keeper *keeper, t_room *room, int prev)
{

    room->prev_room = prev;
	room->in_q = keeper->v_limit;
}