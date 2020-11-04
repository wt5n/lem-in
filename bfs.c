#include "lem_in.h"

#include <stdio.h>

//void	zero_int_mas(int **mas, int length)
//{
//	int i;
//
//	i = 0;
//	while (i < length)
//	{
//		mas[i] = -1;
//		i++;
//	}
//}



int		main(void)
{
	t_room_keeper *keeper = (t_room_keeper*)malloc(sizeof(t_room_keeper));
	keeper->n = (t_room**)ft_memalloc(sizeof(t_room*) * 3000); // nado zanulit
	// keeper->start = (t_room*)malloc(sizeof(t_room));
	// keeper->finish = (t_room*)malloc(sizeof(t_room));

	t_room *start = create_room("Start", 1);
	t_room *finish = create_room("Shavuha", 2);

//	start->visited = 1;
	// keeper->start = start;
	// keeper->finish = finish;

	t_room *a = create_room("A", 3);
	t_room *b = create_room("B", 4);
	t_room *c = create_room("C", 5);
	t_room *d = create_room("D", 6);
	t_room *e = create_room("E", 7);
	t_room *f = create_room("F", 8);
	t_room *g = create_room("G", 9);
	t_room *h = create_room("H", 10);


	// keeper->n[get_hash(finish->name)] = finish;

	// func add room to keeper

    keeper->n[start->id] = start;
    keeper->n[finish->id] = finish;
    keeper->n[a->id] = a;
	keeper->n[b->id] = b;
	keeper->n[c->id] = c;
	keeper->n[d->id] = d;
	keeper->n[e->id] = e;
	keeper->n[f->id] = f;
	keeper->n[g->id] = g;
	keeper->n[h->id] = h;

	keeper->RoomCounter = 10;

    add_two_links(start, a);
    add_two_links(start, b);
	add_two_links(a, c);
	add_two_links(b, d);
	add_two_links(c, f);
	add_two_links(c, e);
	add_two_links(d, f);
	add_two_links(e, h);
	add_two_links(f, g);
	add_two_links(f, finish);
	add_two_links(h, finish);

//    print_all_links(f);
//    ft_printf("%d\n", f->num_of_links);
//    exit(1);

	t_map_keeper *mp;
	mp = (t_map_keeper*)malloc(sizeof(t_map_keeper));
	mp->field = 1;
	mp->rl = (t_room_links*)ft_memalloc(sizeof(t_room_links));
	// mp->rl->data = NULL;
	// mp->rl->next = NULL;
	// mp->next = NULL;
	main_loop(keeper, mp);

	printf("finish");
	return (1);
}