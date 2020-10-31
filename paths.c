#include "lem_in.h"

int	path_to_finish(t_queue *queue, t_room_keeper *keeper)
{
	char *prev;

	prev = keeper->start->name;
	while (queue->stack != NULL)
	{
		t_room *current;

		// char* nnn = ;
		// printf("nnnn %s\n", nnn);

		current = keeper->n[get_hash(out_queue(queue))];
		printf("%s\n", current->name);
		if (current->visited == 0)
		{
			current->visited = 1;
			add_tmp_prev_room(current, prev);

//			ft_printf(("%s is not %s"), current->name, finish->name);
			if (add_links_to_queue(current, queue, keeper) == 1)
			{
				keeper->finish->tmp_prev_room = current->name;
				ft_printf("WIN thw wave is %d", current->wave);
				ft_printf(" thw name is %s\n", current->name);
				return (1);
			}
		}
		prev = current->name;
	}
	return (0);
}

int		length_of_path(t_room_keeper *keeper)
{
	int		length;
	t_room	*current;

	length = 0;
	current = keeper->finish;
	while (current->tmp_prev_room != NULL)
	{
		length++;
		current = keeper->n[get_hash(current->tmp_prev_room)];
	}
	return (length);
}

void	path_to_start(t_room_keeper *keeper, t_map *map)
{
	char 	*current;
	int		length;
	t_map 	*map;

	map->length = length;
	map->field = 0;
	map->rooms = (char**)malloc(sizeof(char*) * map->length);
	map->rooms[length - 1] = (char*)malloc(sizeof(char) * (ft_strlen(keeper->finish->name) + 1));
	map->rooms[length - 1] = ft_strcpy()
	while (length > 0)
	{

	}
}