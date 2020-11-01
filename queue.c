#include "lem_in.h"

static void push(t_list_queue **top_ref, char *new_data)
{
	t_list_queue *new_node = (t_list_queue *) malloc (sizeof (t_list_queue));
	if (new_node == NULL)
	{
		ft_printf ("Stack overflow \n");
		exit (0);
	}
	new_node->name = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

static char *pop(t_list_queue **top_ref)
{
	char *res;
	t_list_queue *top;
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
	push(&q->stack, x);
}

char *out_queue(t_queue *q)
{
	char *x, *res;
	if (q->stack == NULL)
	{
		return NULL;
	}
	else if (q->stack->next == NULL)
		return pop (&q->stack);
	else
	{
		x = pop (&q->stack);
		res = out_queue (q);
		push (&q->stack, x);
		return res;
	}
}
