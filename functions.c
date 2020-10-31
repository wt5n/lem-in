#include "lem_in.h"

void print_all_next(t_room *room)
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

void print_all_links(t_room *room)
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

int get_hash(char *name)
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

void add_next(t_room *master, t_room *slave)
{
	t_room *tmp;

	tmp = master;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = slave;
}

t_queue *min_path_func(t_room_keeper *keeper)
{
	int i = 0;
	int min_wave = MAXINT;
	t_queue *stack = (t_queue *)malloc(sizeof(t_queue));
	t_queue *min_path = (t_queue *)malloc(sizeof(t_queue));
	min_path->stack = NULL;
	while (keeper->finish->links[i])
	{
		if (keeper->n[get_hash(keeper->finish->links[i])]->wave < min_wave)
		{
			min_wave = keeper->n[get_hash(keeper->finish->links[i])]->wave;
			in_queue(stack,keeper->n[get_hash(keeper->finish->links[i])]->name);
		}
		i++;
	}
	i = 0;
	in_queue(stack, keeper->finish->name);
	t_room *current = keeper->n[get_hash(out_queue(stack))];
	while (keeper->n[get_hash(current->links[i])]->wave != 1)
	{
		current = keeper->n[get_hash(out_queue(stack))];
		while (keeper->n[get_hash(current->links[i])]->wave != 1)
		{
			if (keeper->n[get_hash(current->links[i])]->wave < min_wave)
			{
				out_queue(min_path);
				out_queue(stack);
				min_wave = keeper->n[get_hash(current->links[i])]->wave;
				in_queue(stack, keeper->n[get_hash(current->links[i])]->name);
				in_queue(min_path, keeper->n[get_hash(current->links[i])]->name);
			}
			i++;
		}
	}
	return (min_path);
}

void 	final_countdown(t_room_keeper *keeper, char* name, t_queue *queue)
{
	int i;
	t_room 	*room;
	t_room 	*link;
	char 	*min_link;
	int 	min_wave;

	i = 0;
	min_wave = MAXINT;
	room = keeper->n[get_hash(name)];
	while ((room->links[i] != NULL) && (i < room->links_len))
	{
		link = keeper->n[get_hash(room->links[i])];
		if (ft_strcmp(link->name, keeper->finish->name) != 0)
		{
			ft_printf("%s\n", link->name);
			if (link->wave < min_wave)
			{
				min_wave = link->wave;
				min_link = link->name;

				if (min_wave == 1)
					return ;
			}
		}
		i++;
	}
	in_queue(queue, min_link);
	final_countdown(keeper, min_link, queue);
}