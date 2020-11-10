#include "lem_in.h"

unsigned long get_hash(unsigned char *name)
{
	unsigned long hash = 1000;
	int c;

	while ((c = *name++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash % 1000);
}

 void add_next(t_room *master, t_room *slave)
 {
 	t_room *tmp;

 	tmp = master;
 	while (tmp->next != NULL)
 		tmp = tmp->next;
 	tmp->next = slave;
 }

void    print_links(t_room_keeper *keeper, int id)
{
    t_room *room;
    int i;

    room = keeper->n[id];
    i = -1;
    ft_printf("links of room %s\n", room->name);
    while (++i < room->links_count)
    {
        if (room->links_id[0][i] != 0 )
            ft_printf("%d %d\n", room->links_id[0][i], room->links_id[1][i]);
    }
    ft_printf("\n");
}