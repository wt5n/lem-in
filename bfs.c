#include "lem_in.h"

#include <stdio.h>

int	create_hash(char *name)
{
	int hash;

	hash = 0;
	while (*name != '\0')
	{
		hash += *name - '0';
		*name++;
	}
	return hash;
}

t_room	*create_room(char *name)
{
	t_room *room;

	room = (t_room*)malloc(sizeof(t_room));
	room->CheckAnt = 0;
	room->name_room = name;
	room->hash = create_hash(name);
	room->links = (t_link*)malloc(sizeof(t_link));
	room->next = NULL;
	return room;
}

void	add_link(t_room *master, t_room *slave)
{
	t_room *tmp;

	tmp = master;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = slave;
}

void	print_all_links(t_room *room)
{
	t_room *tmp;

	printf("master %s\n", room->name_room);
	tmp = room->next;
	while (tmp != NULL)
	{
		printf("%s ", tmp->name_room);
		tmp = tmp->next;
	}
	printf("\n");
}

int		main(void)
{
	t_room *you = create_room("You");

	t_room *bob = create_room("Bob");
	t_room *alice = create_room("Alice");
	t_room *clair = create_room("Clair");
	add_link(you, bob);
	add_link(you, alice);
	add_link(you, clair);

	t_room *anuj = create_room("Anuj");
	t_room *peggy = create_room("Peggy");
	add_link(bob, anuj);
	add_link(bob, peggy);

	// add_link(alice, peggy);

	// t_room *thom = create_room("Thom");
	// t_room *jonny = create_room("Jonny");
	// add_link(clair, thom);
	// add_link(clair, jonny);


	printf("%s %d\n", you->name_room, you->hash);
	printf("%s %d\n", bob->name_room, bob->hash);
    printf("%s %d\n", alice->name_room, alice->hash);
    printf("%s %d\n", clair->name_room, clair->hash);

	print_all_links(you);

	return (1);
}