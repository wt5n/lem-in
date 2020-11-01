#include "lem_in.h"

// void increase_links(t_room *room)
// {
// 	char **new_links;
// 	int i;

// 	i = 0;
// 	new_links = (char **) malloc((sizeof(char *) * (room->links_len * 2)));
// 	while (i < room->links_len)
// 	{
// 		new_links[i] = (char *) malloc(sizeof(ft_strlen(room->links[i]) + 1));
// 		ft_strcpy(new_links[i], room->links[i]);
// 		free(room->links[i]);
// 		i++;
// 	}
// 	while (i < (room->links_len * 2))
// 	{
// 		new_links[i] = (char *) malloc(sizeof(char));
// 		new_links[i] = NULL;
// 		i++;
// 	}
// 	free(room->links);
// 	room->links = new_links;
// 	room->links_len = room->links_len * 2;
// }

void add_links(t_room *room, char *link)
{
	t_link *tmp_link;
	t_room *tmp_room;

	tmp_room = room;
	if (room->links->name == NULL)
	    room->links->name = ft_strcpy_wm(link);
	else {
        while (tmp_room->links->next != NULL)
            tmp_room->links = room->links->next;
        tmp_link = (t_link*)malloc(sizeof(t_link));
        tmp_link->name = ft_strcpy_wm(link);
        tmp_link->next = NULL;
        tmp_room->links->next = tmp_link;
    }
	room->num_of_links++;
}

void add_two_links(t_room *first, t_room *second)
{
	add_links(first, second->name);
	add_links(second, first->name);
}

int     add_links_to_queue(t_room *room, t_queue *queue, t_room_keeper *c_k2)
{
	t_room	*tmp_room;
	t_room	*tmp_room2;

	tmp_room = room;
	while (tmp_room->num_of_links > 0)
	{
		if (tmp_room->links->used == 0)
		{
			tmp_room2 = c_k2->n[get_hash(tmp_room->links->name)];
			if (ft_strcmp(tmp_room2->name, c_k2->finish->name) == 0)
				return (1);
			if (tmp_room2->visited == 0)
			{
				in_queue(queue, tmp_room2->name);
				printf("%s = \n", tmp_room2->name);
			}
		tmp_room->links = tmp_room->links->next;
		}
		tmp_room->num_of_links--;
	}
	return (0);
}