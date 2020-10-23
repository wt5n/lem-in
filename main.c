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
	room->links = (char**)malloc(sizeof(char*) * 10);
	int i = 0;
	while (i < 10)
	{
        room->links[i] = (char*)malloc(sizeof(char));
		room->links[i] = NULL;
		i++;
	}
	room->links_len = 10;
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

void	print_all_links(t_room *room)
{
    int i;

    i = 0;
    printf("Links of master %s\n", room->name_room);
    while (i < room->links_len)
    {
        if (room->links[i] == NULL)
            break;
        printf("%s ", room->links[i]);
        i++;
    }
    printf("\nEnd of master`s rooms\n");
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



//t_link  *create_link(char *name)
//{
//    char *link;
//
//    link = (t_link*)malloc(sizeof(t_link));
//    link->name = (char*)malloc(sizeof(ft_strlen(name) + 1));
//    ft_strcpy(link->name, name);
//    return link;
//}

int		main(void)
{
	t_room_keeper *rooms = (t_room_keeper*)malloc(sizeof(t_room_keeper));
	rooms->n = (t_room**)malloc(sizeof(t_room*) * 3000);
	ft_printf("%d\n", create_hash("Qwer"));
	ft_printf("%d\n", create_hash("aeswrqwerqwegdasd213421erqwertyreg345gewrgwergwerhjwretwert"));

	t_room *you = create_room("You");
	t_room *anuj = create_room("Anuj");

	anuj->hash = 173;
	rooms->n[173] = you;

	add_links(you, "Alice");
    add_links(you, "2");
    add_links(you, "3");
    add_links(you, "4");
    add_links(you, "5");
    add_links(you, "6");
    add_links(you, "7");
    add_links(you, "8");
    add_links(you, "9");
    add_links(you, "10");

    add_links(anuj, "BB");

	print_all_links(you);
    print_all_links(anuj);

    add_links(you, "11");
    print_all_links(you);
    ft_printf("%d\n", you->links_len);

//    add_links(you, "Alice");

	// while (rooms->n[173]->links != NULL)
	// {
	// 	printf("%s ", rooms->n[173]->links->stack1->name);
	// 	rooms->n[173]->links->stack1->next;
	// }
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