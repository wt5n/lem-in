#include "libft/libft.h"
#include "lem_in.h"


int main()
{
	t_queue *q = (t_queue *) malloc (sizeof (t_queue));
	q->stack1 = NULL;
	enQueue (q, "hello");
	enQueue (q, "world");
	ft_printf("%d\n", 1);
	ft_printf ("%s ", deQueue (q));
	ft_printf ("%s ", deQueue (q));
	free(q);
	return 0;
}