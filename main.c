#include "lem_in.h"

int	create_hash(char *name)
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

//void	add_link(t_room master, t_room link)
//{
//	t_link *newlin;
//
//	int i = 0;
//	int count_of_link = ();
//	newlin = (t_link*)malloc(sizeof(t_list) * (count_of_link + (count_of_link / 2)));
//	while (i < count_of_link)
//	{
//		newlin[i] = master->link[i];
//		free(master->link[i]);
//		i++
//	}
//	master->link = newlin;
//}

t_room	*create_room(char *name)
{
	t_room *room = (t_room*)malloc(sizeof(t_room));

	room->CheckAnt = 0;
	room->name_room = name;
	room->hash = create_hash(name);
	room->next = NULL;
	room->links = (t_queue*)malloc(sizeof(t_queue));
	room->links = NULL;
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

void	print_all_next(t_room *room)
{
	t_room *tmp;

	printf("master %s\n", room->name_room);
	tmp = room->next;
	while (tmp != NULL)
	{
		printf("%s ", tmp->name_room);
		tmp = tmp->next;
	}
	printf("\nEnd of master`s rooms\n");

}
// 6-5
void    add_links(t_room *room, t_room_keeper *keeper, char *link)
{
	t_room *tmp;
	tmp = keeper->n[room->hash];
	printf("%d\n", room->hash);
	ft_printf("%s\n", keeper->n[room->hash]->name_room);
	while (ft_strcmp(keeper->n[room->hash]->name_room, tmp->name_room) != 0)
		tmp = tmp->next;
	in_queue(keeper->n[room->hash]->links, link);
}

int		main(void)
{
	t_room_keeper *rooms = (t_room_keeper*)malloc(sizeof(t_room_keeper));
	rooms->n = (t_room**)malloc(sizeof(t_room*) * 3000);
	t_room *you = create_room("You");
	t_room *anuj = create_room("Anuj");
	anuj->hash = 173;
	rooms->n[173] = you;
	add_links(you, rooms, "Alice");
	add_links(anuj, rooms, "BB");
	while (rooms->n[173]->links != NULL)
	{
		printf("%s ", rooms->n[173]->links->stack1->name);
		rooms->n[173]->links->stack1->next;
	}
//	in_queue(rooms->n[0].links, "Bob");
//	in_queue(rooms->n[0].links, "Clair");
//	in_queue(rooms->n[0].next->links, "1");
//	in_queue(rooms->n[0].next->links, "2");
//	printf("master %s links: %s, %s\n", rooms->n[0].name_room, out_queue(rooms->n[0].links),
//		out_queue(rooms->n[0].links));
//	in_queue(rooms->n[0].next->links, "Alice");
//	in_queue(rooms->n[0].next->links, "Clair");
//	printf("slave %s links: %s, %s\n", rooms->n[0].next->name_room,
//		out_queue(rooms->n[0].next->links), out_queue(rooms->n[0].next->links));
//	t_room bob = create_room("Bob");
//	t_room alice = create_room("Alice");
//	t_room clair = create_room("Clair");
//
//	rooms->n[1] = bob;
//	rooms->n[2] = alice;
//	rooms->n[3] = clair;



//	t_room *peggy = create_room("Peggy");
//	 add_link(bob, anuj);
//	 add_link(bob, peggy);

//	 add_link(alice, peggy);

	// t_room *thom = create_room("Thom");
	// t_room *jonny = create_room("Jonny");
	// add_link(clair, thom);
	// add_link(clair, jonny);


//	printf("%s %d\n", you->name_room, you->hash);
//	printf("%s %d\n", anuj->name_room, anuj->hash);
//	printf("%s %d\n", alice->name_room, alice->hash);
//	printf("%s %d\n", clair->name_room, clair->hash);
//
//	print_all_next(you);

	return (0);
}