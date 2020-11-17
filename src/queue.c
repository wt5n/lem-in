/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:10:34 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/17 17:14:51 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static void		push(t_list_queue **top_ref, int new_data)
{
	t_list_queue *new_node;

	if (!(new_node = (t_list_queue*)malloc(sizeof(t_list_queue))))
		return ;
	new_node->id = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

static int		pop(t_list_queue **top_ref)
{
	int				res;
	t_list_queue	*top;

	if (*top_ref == NULL)
		return (0);
	else
	{
		top = *top_ref;
		res = top->id;
		*top_ref = top->next;
		free(top);
		return (res);
	}
}

void			in_queue(t_queue *q, int x)
{
	push(&q->stack, x);
}

int				out_queue(t_queue *q)
{
	int x;
	int	res;

	if (q->stack == NULL)
		return (0);
	else if (q->stack->next == NULL)
		return (pop(&q->stack));
	else
	{
		x = pop(&q->stack);
		res = out_queue(q);
		push(&q->stack, x);
		return (res);
	}
}
