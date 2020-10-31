#include "lem_in.h"

void increase_links(t_room *room)
{
	char **new_links;
	int i;

	i = 0;
	new_links = (char **) malloc((sizeof(char *) * (room->links_len * 2)));
	while (i < room->links_len)
	{
		new_links[i] = (char *) malloc(sizeof(ft_strlen(room->links[i]) + 1));
		ft_strcpy(new_links[i], room->links[i]);
		free(room->links[i]);
		i++;
	}
	while (i < (room->links_len * 2))
	{
		new_links[i] = (char *) malloc(sizeof(char));
		new_links[i] = NULL;
		i++;
	}
	free(room->links);
	room->links = new_links;
	room->links_len = room->links_len * 2;
}

// 6-5
void add_links(t_room *room, char *link)
{
	int i;

	i = 0;
	while (i < room->links_len)
	{
		if (room->links[i] == NULL)
		{
			room->links[i] = (char *)malloc(sizeof(ft_strlen(link) + 1));
			room->links[i] = ft_strcpy(room->links[i], link);
			return;
		}
		i++;
	}
	increase_links(room);
	add_links(room, link);
}

void add_two_links(t_room *first, t_room *second)
{
	add_links(first, second->name);
	add_links(second, first->name);
}

int add_links_to_queue(t_room *room, t_queue *queue, t_room_keeper *keeper)
{
	int i;
	t_room *link;

	i = 0;
	while ((room->links[i] != NULL) && (i < room->links_len))
	{

		link = keeper->n[get_hash(room->links[i])];
		// if (ft_strcmp(room->name, "H") == 0)
		// 	printf("%s\n", link->name);
		if (ft_strcmp(link->name, keeper->finish->name) == 0)
			return (1);
		if (link->visited == 0)
		{
			in_queue(queue, room->links[i]);
			link->wave = room->wave + 1;
			printf("%s = wave %d\n", link->name, link->wave);
		}
		// ft_printf("%d\n", keeper->n[get_hash(start->links[i])]);
		i++;
	}
	return (0);
}