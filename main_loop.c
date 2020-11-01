#include "lem_in.h"


int		delete_collisions(t_room_keeper *c_k1, t_map_keeper *keeper)
{
	return (0);
}

void	main_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
	t_room_keeper	*c_k1;

	c_k1 = keeper;
	while (path_to_finish(c_k1, mp) != 0)
		;
	if ((delete_collisions(c_k1, keeper)) == 1)
	{
		mp->field++;
		main_loop(keeper, mp);
	}
}