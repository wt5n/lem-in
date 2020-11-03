#include "lem_in.h"

t_room *create_room(char *name, int id)
{
	t_room *room = (t_room *)ft_memalloc(sizeof(t_room));

	// room->CheckAnt = 0;
	room->name = ft_strcpy_wm(name);
	room->id = id;
	room->links_id = (int*)ft_memalloc(sizeof(int) * 10);
	room->links_used = (int*)ft_memalloc(sizeof(int) * 10);
	room->links_count = 10;
	// room->hash = get_hash(name);
	// room->next = NULL;
	// room->links = (t_link*)ft_memalloc(sizeof(t_link));
	// room->links->name = NULL;
	// room->links->used = 0;
	// room->links->next = NULL;
	// room->num_of_links = 0;
	// room->visited = 0;
	// room->prev_room = NULL;
	return room;
}

void	add_prev_room(t_room *room, int prev)
{
	// char *room_name;

	// if (room->prev_room != NULL)
		// free(room->prev_room);
	// room_name = (char*)malloc(sizeof(char) * (ft_strlen(prev) + 1));
	// room->prev_room = ft_strcpy(room_name, prev);
	room->prev_room = prev;
	ft_printf("     room %d has prev %d\n", room->id, prev);
}