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
	t_room *a = create_room("A");
	t_room *b = create_room("B");
	t_room *c = create_room("C");
	t_room *d = create_room("D");
	t_room *e = create_room("E");
	t_room *f = create_room("F");
	t_room *g = create_room("G");
	t_room *h = create_room("H");
	t_room *finish = create_room("Shavuha");


	keeper->start = start;
	keeper->finish = finish;

	start->wave = 0;
	start->visited = 1;

	keeper->n[get_hash(finish->name)] = finish;
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

	t_queue *queue;
	queue = (t_queue*)malloc(sizeof(t_queue));
	queue->stack = NULL;


	add_links_to_queue(start, queue, keeper);

	while (queue->stack != NULL)
	{
		t_room *current;

		// char* nnn = ;
		// printf("nnnn %s\n", nnn);

		current = keeper->n[get_hash(out_queue(queue))];
		printf("%s\n", current->name);
		if (current->visited == 0)
		{
			current->visited = 1;

//			ft_printf(("%s is not %s"), current->name, finish->name);
			if (add_links_to_queue(current, queue, keeper) == 1)
			{
				ft_printf("WIN thw wave is %d", current->wave);
				ft_printf(" thw name is %s\n", current->name);
				break;
			}
		}
	}
	


	return (1);
}