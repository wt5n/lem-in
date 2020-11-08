#include "lem_in.h"

//void	zero_int_mas(int **mas, int length)
//{
//	int i;
//
//	i = 0;
//	while (i < length)
//	{
//		mas[i] = -1;
//		i++;
//	}
//}



int		main(void)
{
	t_room_keeper *keeper = (t_room_keeper*)ft_memalloc(sizeof(t_room_keeper));
	keeper->n_hash = (t_room**)ft_memalloc(sizeof(t_room*) * 3000);
	keeper->RoomCounter = 3;
	parse_input(keeper);
	keeper->n = (t_room**)ft_memalloc(sizeof(t_room*) * keeper->RoomCounter);
	pass_to_n(keeper);

	t_map_keeper *mp;
	mp = (t_map_keeper*)malloc(sizeof(t_map_keeper));
	mp->field = 1;
	mp->rl = (t_room_links*)ft_memalloc(sizeof(t_room_links));
	// mp->rl->data = NULL;
	// mp->rl->next = NULL;
	// mp->next = NULL;
	main_loop(keeper, mp);

	printf("finish");
	return (1);
}