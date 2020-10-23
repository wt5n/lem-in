#include "lem_in.h"

static void push (t_link **top_ref, char *new_data)
{
	t_link *new_node = (t_link *) malloc (sizeof (t_link));
	if (new_node == NULL)
	{
		printf ("Stack overflow \n");
		getchar ();
		exit (0);
	}
	new_node->name = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

static char *pop (t_link **top_ref)
{
	char *res;
	t_link *top;
	if (*top_ref == NULL)
	{
		printf ("Stack underflow \n");
		getchar ();
		exit (0);
	}
	else
	{
		top = *top_ref;
		res = top->name;
		*top_ref = top->next;
		free (top);
		return res;
	}
}

void enQueue(t_queue *q, char *x)
{
	push (&q->stack1, x);
}

char *deQueue(t_queue *q)
{
	char *x, *res;
	if (q->stack1 == NULL)
	{
		printf ("Q is empty");
		getchar ();
		exit (0);
	}
	else if (q->stack1->next == NULL)
		return pop (&q->stack1);
	else
	{
		x = pop (&q->stack1);
		res = deQueue (q);
		push (&q->stack1, x);
		return res;
	}
}
