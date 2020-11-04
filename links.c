#include "lem_in.h"

void increase_links(t_room *room)
{
	int	**new_links;
	int i;

	i = -1;
	new_links = (int**)ft_memalloc((sizeof(int*) * 2));
	new_links[0] = (int*)ft_memalloc((sizeof(int) * (room->links_count * 2)));
	new_links[1] = (int*)ft_memalloc((sizeof(int) * (room->links_count * 2)));
	while (++i < room->links_count)
		new_links[0][i] = room->links_id[0][i];
	free(room->links_id[0]);
	room->links_id = new_links;
	room->links_count = room->links_count * 2;
}

void add_links(t_room *room, int link)
{
	int i;

	i = -1;
	while (++i < room->links_count)
	{
		if (room->links_id[0][i] == 0)
		{
			room->links_id[0][i] = link;
			return ;
		}
	}
	increase_links(room);
	add_links(room, link);
}

void add_two_links(t_room *first, t_room *second)
{
	add_links(first, second->id);
	add_links(second, first->id);
}

int     add_links_to_queue(int id, t_queue *queue, t_room_keeper *keeper)
{
	int     num_of_links;
	t_room	*tmp_room;
	int		i;

	i = -1;
	tmp_room = keeper->n[id];
	num_of_links = tmp_room->links_count;
	while (++i < num_of_links)
	{
		// mark_as_used
		if ((tmp_room->links_id[0][i] != 0) && (tmp_room->links_id[1][i] == 0))
		{
			ft_printf("link id is %d\n", tmp_room->links_id[0][i]);
			if (tmp_room->links_id[0][i] == 2)
			{
				add_prev_room(keeper->n[tmp_room->links_id[0][i]], tmp_room->id);
			    ft_printf("the kraynaya komnata is %s\n", tmp_room->name);
                return (1);
            }
			if (keeper->n[tmp_room->links_id[0][i]]->visited == 0)
			{
				add_prev_room(keeper->n[tmp_room->links_id[0][i]], tmp_room->id);
				in_queue(queue, tmp_room->links_id[0][i]);
//				printf("%s  \n", tmp_room2->name);
			}
		}
	}
	return (0);
}