/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:00:54 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/17 17:14:51 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		del_cols2(t_room_keeper *keeper, int room, int linked_room, int num_lrm)
{
	t_room	*rm;
	t_room	*l_rm;
	int		i;

	i = -1;
	rm = keeper->n[room];
	l_rm = keeper->n[linked_room];
	while (++i < rm->links_count)
	{
		if (rm->links_id[0][i] == linked_room && rm->links_id[1][i] != 1 &&
			(room != 1 && room != 2) && (linked_room != 1 && linked_room != 2))
		{
			rm->links_id[0][i] = 0;
			l_rm->links_id[0][num_lrm] = 0;
			return (1);
		}
	}
	return (0);
}

int		del_col1(t_room_keeper *keeper, t_queue *queue)
{
	t_room	*r;
	t_room	*lin_r;
	int		i;
	int		t;

	while (queue->stack != NULL)
	{
		r = keeper->n[out_queue(queue)];
		i = -1;
		while (++i < r->links_count)
		{
			if (r->visd < 1000001 && r->links_id[0][i] > 0)
			{
				lin_r = keeper->n[r->links_id[0][i]];
				t = find_room(keeper, lin_r->id, r->id);
				if (t != -1 && lin_r->links_id[1][t] == 1)
					if (del_cols2(keeper, r->id, lin_r->id, t))
						return (1);
				if (t != -1 && r->links_id[1][i] != 1 && lin_r->visd < 1000001)
					in_queue(queue, r->links_id[0][i]);
			}
		}
		r->visd = 1000001;
	}
	return (0);
}

int		delete_collisions(t_room_keeper *keeper)
{
	t_queue	*queue;
	int		res;

	if (!(queue = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (0);
	in_queue(queue, 2);
	res = del_col1(keeper, queue);
	free_queue(queue);
	return (res);
}
