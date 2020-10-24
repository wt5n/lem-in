#include "lem_in.h"

#include <stdio.h>

void	zero_int_mas(int **mas, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		mas[i] = -1;
		i++;
	}
}



int		main(void)
{
	t_room_keeper *keeper = (t_room_keeper*)malloc(sizeof(t_room_keeper));
	keeper->n = (t_room**)malloc(sizeof(t_room*) * 3000); // nado zanulit

	t_room *you = create_room("You");
	t_room *bob = create_room("Bob");
	t_room *alice = create_room("Alice");
	t_room *clair = create_room("Clair");

	keeper->n[get_hash(you->name_room)] = you;
	keeper->n[get_hash(bob->name_room)] = bob;
	keeper->n[get_hash(alice->name_room)] = alice;
	keeper->n[get_hash(clair->name_room)] = clair;


	ft_printf("%s %d\n", keeper->n[get_hash(you->name_room)]->name_room, keeper->n[get_hash(you->name_room)]->hash);

	add_links(you, "Bob");
	add_links(you, "Aiice");
	add_links(you, "Clair");

	 t_room *anuj = create_room("Anuj");
	 t_room *peggy = create_room("Peggy");
	keeper->n[get_hash(anuj->name_room)] = anuj;
	keeper->n[get_hash(peggy->name_room)] = peggy;

	 add_links(bob, "Anuj");
	 add_links(bob, "Peggy");

	 add_links(alice, "Peggy"); // dvoynaya ssilka

	int **checked;
	checked = (int**)malloc(sizeof(int*) * 3000);
	zero_int_mas(checked, 3000);

	int **not_checked;
	not_checked = (int**)malloc(sizeof(int*) * 3000);
	zero_int_mas(not_checked, 3000);

	while (1)
	{

	}

//	 add_link(alice, peggy);

	// t_room *thom = create_room("Thom");
	// t_room *jonny = create_room("Jonny");
	// add_link(clair, thom);
	// add_link(clair, jonny);


	// printf("%s %d\n", you->name_room, you->hash);
	// printf("%s %d\n", bob->name_room, bob->hash);
    // printf("%s %d\n", alice->name_room, alice->hash);
    // printf("%s %d\n", clair->name_room, clair->hash);

	// print_all_next(you);

	return (1);
}