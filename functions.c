#include "lem_in.h"

//void print_all_next(t_room *room)
//{
//	t_room *tmp;
//
//	printf("master %s\n", room->name);
//	tmp = room->next;
//	while (tmp != NULL)
//	{
//		printf("%s ", tmp->name);
//		tmp = tmp->next;
//	}
//	printf("\nEnd of master`s rooms\n");
//}

void print_all_links(char *name, t_link *links)
{
    t_link  *tmp_links;

    tmp_links = links;
    printf(" * *Links of master %s\n", name);
    while (tmp_links->next != NULL)
	{
		printf("%s and is used=%d ", tmp_links->name, tmp_links->used);
		tmp_links = tmp_links->next;
	}
	printf("\nEnd of master`s rooms\n");
//	t_room *tmp_room;
//
//	tmp_room = room;
//	printf("Links of master %s\n", tmp_room->name);
//	while (tmp_room->links->next != NULL)
//	{
//		printf("%s ", tmp_room->links->name);
//		tmp_room->links = tmp_room->links->next;
//	}
//	printf("%s ", tmp_room->links->name);
//	printf("\nEnd of master`s rooms\n");
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

// void add_next(t_room *master, t_room *slave)
// {
// 	t_room *tmp;

// 	tmp = master;
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	tmp->next = slave;
// }
