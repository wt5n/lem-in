#include "lem_in.h"

void	print_all_next(t_room *room)
{
	t_room *tmp;

	printf("master %s\n", room->name);
	tmp = room->next;
	while (tmp != NULL)
	{
		printf("%s ", tmp->name);
		tmp = tmp->next;
	}
	printf("\nEnd of master`s rooms\n");
}

void	print_all_links(t_room *room)
{
    int i;

    i = 0;
    printf("Links of master %s\n", room->name);
    while (i < room->links_len)
    {
        if (room->links[i] == NULL)
            break;
        printf("%s ", room->links[i]);
        i++;
    }
    printf("\nEnd of master`s rooms\n");
}

int	get_hash(char *name)
{
	int hash;

	hash = 0;
	while (*name != '\0')
	{
		hash += *name - '0';
		name++;
	}
	return hash;
}

t_room	*create_room(char *name)
{
	t_room *room = (t_room*)malloc(sizeof(t_room));

	room->CheckAnt = 0;
	room->name = name;
	room->hash = get_hash(name);
	room->next = NULL;
	room->links = (char**)malloc(sizeof(char*) * 10);
	int i = 0;
	while (i < 10)
	{
        room->links[i] = (char*)malloc(sizeof(char));
		room->links[i] = NULL;
		i++;
	}
	room->links_len = 10;
	room->visited = 0;
	room->wave = 0;
	return room;
}

void	add_next(t_room *master, t_room *slave)
{
	t_room *tmp;

	tmp = master;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = slave;
}

void    increase_links(t_room *room)
{
    char  **new_links;
    int i;

    i = 0;
    new_links = (char**)malloc((sizeof(char*) * (room->links_len * 2)));
    while (i < room->links_len)
    {
        new_links[i] = (char*)malloc(sizeof(ft_strlen(room->links[i]) + 1));
        ft_strcpy(new_links[i], room->links[i]);
        free(room->links[i]);
        i++;
    }
    while (i <  (room->links_len * 2))
    {
        new_links[i] = (char*)malloc(sizeof(char));
        new_links[i] = NULL;
        i++;
    }
    free(room->links);
    room->links = new_links;
    room->links_len = room->links_len * 2;
}

// 6-5
void    add_links(t_room *room, char *link)
{
	int i;

	i = 0;
	while (i < room->links_len)
    {
	    if (room->links[i] == NULL) {
            room->links[i] = (char*)malloc(sizeof(ft_strlen(link) + 1));
            room->links[i] = ft_strcpy(room->links[i], link);
            return;
        }
	    i++;
    }
	increase_links(room);
	add_links(room, link);
}

void	add_two_links(t_room *first, t_room *second)
{
	add_links(first, second->name);
	add_links(second, first->name);
}

void	add_links_to_queue(t_room *room, t_queue *queue, t_room_keeper *keeper)
{
	int i;

	i = 0;
	while (room->links[i] != NULL && i < room->links_len)
	{
		if (room->visited == 0)
		{
			in_queue(queue, room->links[i]);
			keeper->n[get_hash(room->links[i])]->wave += 1;
		}
		// ft_printf("%d\n", keeper->n[get_hash(start->links[i])]);
		i++;
	}
}