#include "lem_in.h"


int		delete_collisions(t_room_keeper *c_k1, t_map_keeper *keeper)
{
	return (0);
}

void	main_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
    int             i;

    i = 1;
	while (i != 0)
        i = path_to_finish(keeper, mp);
	if ((delete_collisions(keeper, mp)) == 1)
	{
		mp->field++;
		main_loop(keeper, mp);
	}
}