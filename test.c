#include "lem_in.h"

int main (void)
{
	t_room_keeper *keeper = (t_room_keeper*)ft_memalloc(sizeof(t_room_keeper));
	keeper->n_hash = (t_room**)ft_memalloc(sizeof(t_room*) * 3000);
	keeper->RoomCounter = 3;
	parse_input(keeper);
	keeper->n = (t_room**)ft_memalloc(sizeof(t_room*) * keeper->RoomCounter);

	printf("%s  id = %d\n", keeper->start->name, keeper->start->id);
	printf("%s  id = %d\n", keeper->n_hash[get_hash("Shavuha")]->name, keeper->n_hash[get_hash("Shavuha")]->id);
	printf("%s  id = %d\n", keeper->n_hash[get_hash("H")]->name, keeper->n_hash[get_hash("H")]->id);
	printf("%d\n", keeper->RoomCounter);
	pass_to_n(keeper);
	for(int i = 0; i < keeper->RoomCounter; i++)
	{
		if (keeper->n[i])
			printf ("id = %d - name -> %s\n hash = %lu\n", keeper->n[i]->id, keeper->n[i]->name, get_hash(keeper->n[i]->name));
	}

	return 0;
} 