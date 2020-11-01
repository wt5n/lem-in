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
	int i;
	t_link *tmp_link;


	// i = 0;
	tmp_link = room->links;
	while (tmp_link != NULL)
	{
		tmp_link = room->links->next;
		room->links = tmp_link;
		// tmp_link = tmp_link->li
	}

	room->links->name = ft_strcpy_wm(link);
	room->links->next = NULL;


	// while (i < room->links_len)
	// {
	// 	if (room->links[i] == NULL)
	// 	{
	// 		room->links[i] = (char *)malloc(sizeof(ft_strlen(link) + 1));
	// 		room->links[i] = ft_strcpy(room->links[i], link);
	// 		return;
	// 	}
	// 	i++;
	// }
	// increase_links(room);
	// add_links(room, link);
}

void add_two_links(t_room *first, t_room *second)
{
	add_links(first, second->name);
	add_links(second, first->name);
}

void add_links_to_queue(t_room *room, t_queue *queue, t_room_keeper *c_k2)
{
	// int i;
	// t_room *link;

	// i = 0;
	t_link *tmp_link;
	t_room	*tmp_room;

	tmp_link = room->links;
	while (tmp_link->next != NULL)
	{
		if (tmp_link->used == 0)
		{
			tmp_room = c_k2->n[get_hash(tmp_link->name)];
			// if (ft_strcmp(room->name, "H") == 0)
			// 	printf("%s\n", link->name);
			if (ft_strcmp(tmp_room->name, c_k2->finish->name) == 0)
				return (1);
			if (tmp_room->visited == 0)
			{
				in_queue(queue, tmp_link->name);
				printf("%s = \n", tmp_link->name);
			}
			// ft_printf("%d\n", keeper->n[get_hash(start->links[i])]);
			// i++;
		}
		tmp_link = ...
	}
	return (0);
}