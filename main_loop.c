#include "lem_in.h"


int		delete_collisions(t_room_keeper *c_k1, t_map_keeper *keeper)
{
	return (0);
}

int		main_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
	t_room_keeper	*c_k1;

	c_k1 = keeper;
	while (1)
		if (path_to_finish(c_k1, mp) == 0)
			break;
	if ((delete_collisions(c_k1, keeper)) == 1)
	{
		mp->field++;
		main_loop(keeper, mp);
	}
}