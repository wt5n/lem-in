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
	keeper->n = (t_room**)malloc(sizeof(t_room*) * 3000); // nado zanulit
	keeper->start = (t_room*)malloc(sizeof(t_room));
	keeper->finish = (t_room*)malloc(sizeof(t_room));

	t_room *start = create_room("Start");
	t_room *finish = create_room("Shavuha");
	start->visited = 1;
	keeper->start = start;
	keeper->finish = finish;

	t_room *a = create_room("A");
	t_room *b = create_room("B");
	t_room *c = create_room("C");
	t_room *d = create_room("D");
	t_room *e = create_room("E");
	t_room *f = create_room("F");
	t_room *g = create_room("G");
	t_room *h = create_room("H");

	// keeper->n[get_hash(finish->name)] = finish;

	// func add room to keeper

	keeper->n[get_hash(a->name)] = a;
	keeper->n[get_hash(b->name)] = b;
	keeper->n[get_hash(c->name)] = c;
	keeper->n[get_hash(d->name)] = d;
	keeper->n[get_hash(e->name)] = e;
	keeper->n[get_hash(f->name)] = f;
	keeper->n[get_hash(g->name)] = g;
	keeper->n[get_hash(h->name)] = h;

	add_links(start, a->name);
	add_links(start, b->name);
	add_two_links(a, c);
	add_two_links(b, d);
	add_two_links(a, c);
	add_two_links(c, f);
	add_two_links(c, e);
	add_two_links(d, f);
	add_two_links(e, h);
	add_two_links(f, g);
	add_two_links(f, finish);
	add_two_links(h, finish);

    print_all_links(f);

	t_map_keeper *mp;
	mp = (t_map_keeper*)malloc(sizeof(t_map_keeper));
	mp->field = 1;
	mp->next = NULL;
	main_loop(keeper, mp);

	return (1);
}