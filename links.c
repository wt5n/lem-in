#include "lem_in.h"

void increase_links(t_room *room)
{
	int	**new_links;
	int i;

	i = -1;
	if (!(new_links = (int**)ft_memalloc((sizeof(int*) * 2))))
		return ;
	if	(!(new_links[0] = (int*)ft_memalloc((sizeof(int) * (room->links_count * 2)))))
		return ;
	if	(!(new_links[1] = (int*)ft_memalloc((sizeof(int) * (room->links_count * 2)))))
		return ;
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
	t_room	*tmp_room;
	int		i;
	int     index;

	i = -1;
	tmp_room = keeper->n[id];
	while (++i < tmp_room->links_count)
	{
		if ((tmp_room->links_id[0][i] != 0) && (tmp_room->links_id[1][i] == 0))
		{
			if (tmp_room->links_id[0][i] == 2)
			{
                keeper->n[tmp_room->links_id[0][i]]->prev_room = tmp_room->id;
                keeper->n[tmp_room->links_id[0][i]]->in_q = keeper->v_limit;
			    if (tmp_room->id == 1 && tmp_room->links_id[0][i] == 2)
			    {
			    	tmp_room->links_id[0][i] = 0;
				    tmp_room->links_id[1][i] = 0;
				    index = find_room(keeper,  2, 1);
				    keeper->n[2]->links_id[0][index] = 0;
				    keeper->n[2]->links_id[1][index] = 0;
			    }
                return (1);
            }
			if (keeper->n[tmp_room->links_id[0][i]]->visited < keeper->v_limit &&
				keeper->n[tmp_room->links_id[0][i]]->in_q < keeper->v_limit)
			{
                keeper->n[tmp_room->links_id[0][i]]->prev_room = tmp_room->id;
                keeper->n[tmp_room->links_id[0][i]]->in_q = keeper->v_limit;
				in_queue(queue, tmp_room->links_id[0][i]);
			}
		}
	}
	return (0);
}