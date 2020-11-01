#include "lem_in.h"

t_room *create_room(char *name)
{
	t_room *room = (t_room *)malloc(sizeof(t_room));

	room->CheckAnt = 0;
	room->name = ft_strcpy_wm(name);
	room->hash = get_hash(name);
	room->next = NULL;
	room->links = (t_link*)malloc(sizeof(t_link));
	room->links->name = NULL;
	room->links->used = 0;
	room->links->next = NULL;
	room->num_of_links = 0;
	room->visited = 0;
	room->prev_room = NULL;
	return room;
}

void	add_prev_room(t_room *room, char *prev)
{
	char *room_name;

	if (room->prev_room != NULL)
		free(room->prev_room);
	room_name = (char*)malloc(sizeof(char) * (ft_strlen(prev) + 1));
	room->prev_room = ft_strcpy(room_name, prev);
	ft_printf("     room %s has prev %s\n", room->name, prev);
}