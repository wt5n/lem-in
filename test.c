#include "lem_in.h"

int main (void)
{
	t_room_keeper *keeper = (t_room_keeper*)ft_memalloc(sizeof(t_room_keeper));
	keeper->n_hash = (t_room**)ft_memalloc(sizeof(t_room*) * 3000);
	keeper->RoomCounter = 3;
	parse_input(keeper);
	keeper->n = (t_room**)ft_memalloc(sizeof(t_room*) * keeper->RoomCounter);

	printf("%s  id = %d\n", keeper->start->name, keeper->start->id);
	printf("%s  id = %d\n", keeper->n_hash[get_hash("room3")]->name, keeper->n_hash[get_hash("room3")]->id);
	printf("%s  id = %d\n", keeper->n_hash[get_hash("room1")]->name, keeper->n_hash[get_hash("room1")]->id);
	printf("%d\n", keeper->n_hash[(get_hash("room1"))]->links_id[1]);
	printf("%d\n", keeper->n_hash[(get_hash("room1"))]->links_id[0]);
	printf("%d\n", keeper->n_hash[(get_hash("room1"))]->links_id[2]);
	return 0;
} 