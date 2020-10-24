#include "lem_in.h"





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

	// add_links(you, "Alice");
    // add_links(you, "2");
    // add_links(you, "3");
    // add_links(you, "4");
    // add_links(you, "5");
    // add_links(you, "6");
    // add_links(you, "7");
    // add_links(you, "8");
    // add_links(you, "9");
    // add_links(you, "10");

    // add_links(anuj, "BB");

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