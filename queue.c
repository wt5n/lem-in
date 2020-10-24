#include "lem_in.h"

static void push(t_link **top_ref, char *new_data)
{
	t_link *new_node = (t_link *) malloc (sizeof (t_link));
	if (new_node == NULL)
	{
		ft_printf ("Stack overflow \n");
		exit (0);
	}
	new_node->name = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

static char *pop(t_link **top_ref)
{
	char *res;
	t_link *top;
	if (*top_ref == NULL)
	{
		ft_printf ("Stack underflow \n");
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

void in_queue(t_queue *q, char *x)
{
	push (&q->stack1, x);
}

char *out_queue(t_queue *q)
{
	char *x, *res;
	if (q->stack1 == NULL)
	{
		return("Queue is empty");
	}
	else if (q->stack1->next == NULL)
		return pop (&q->stack1);
	else
	{
		x = pop (&q->stack1);
		res = out_queue (q);
		push (&q->stack1, x);
		return res;
	}
}