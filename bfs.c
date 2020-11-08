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

void		find_count_s_f(t_room_keeper *keeper)
{
	t_room 	room;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < keeper->n[1]->links_count)
		if (keeper->n[1]->links_id[0][i] != 0)
			j++;
	keeper->s_links = j;
	j = 0;
	i = -1;
	while (++i < keeper->n[2]->links_count)
		if (keeper->n[2]->links_id[0][i] != 0)
			j++;
	keeper->f_links = j;
}

int		main(void)
{
	t_room_keeper *keeper = (t_room_keeper*)ft_memalloc(sizeof(t_room_keeper));
	keeper->n_hash = (t_room**)ft_memalloc(sizeof(t_room*) * 3000);
	keeper->RoomCounter = 3;
	parse_input(keeper);
	keeper->n = (t_room**)ft_memalloc(sizeof(t_room*) * keeper->RoomCounter);
	pass_to_n(keeper);

	t_map_keeper *mp;
	mp = (t_map_keeper*)ft_memalloc(sizeof(t_map_keeper));
	mp->field = 1;
	mp->rl = (t_room_links*)ft_memalloc(sizeof(t_room_links));
	find_count_s_f(keeper);
	printf("%d %d\n", keeper->s_links, keeper->f_links);
	main_loop(keeper, mp);

	printf("finish");
	return (1);
}