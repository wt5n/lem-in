#include "lem_in.h"

t_room *create_room(char *name)
{
	t_room *room = (t_room *)malloc(sizeof(t_room));

	room->CheckAnt = 0;
	room->name = ft_strcpy_wm(name);
	room->hash = get_hash(name);
	room->next = NULL;
	room->links = (char**)malloc(sizeof(char*) * 10);
	int i = 0;
	while (i < 10)
	{
		room->links[i] = (char*)malloc(sizeof(char));
		room->links[i] = NULL;
		i++;
	}
	room->links_len = 10;
	room->visited = 0;
	room->wave = 0;
	// room->forward = 0;
	// room->back = 0;
	room->tmp_prev_room = NULL;
	room->prev_room = NULL;
	return room;
}

void	add_tmp_prev_room(t_room *room, char **prev)
{
	char *room_name;

	if (room->tmp_prev_room != NULL)
		free(room->tmp_prev_room);
	room_name = (char*)malloc(sizeof(char) * (ft_strlen(prev) + 1));
	room->tmp_prev_room = ft_strcpy(room_name, prev);
}

void	add_prev_room(t_room *room, char **prev)
{
	char *room_name;

	if (room->prev_room != NULL)
		free(room->prev_room);
	room_name = (char*)malloc(sizeof(char) * (ft_strlen(prev) + 1));
	room->prev_room = ft_strcpy(room_name, prev);
}