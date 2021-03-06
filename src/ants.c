/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:59:56 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/18 00:38:08 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		ant_move(t_room_keeper *k, t_room_links *tmp, int inc_ant, int i)
{
	t_room *cur;

	cur = k->n[tmp->data->rooms[i]];
	if (i == 1)
	{
		if (i == tmp->data->length - 2)
		{
			if (cur->ant_num > 0)
			{
				tmp->data->ants_counter--;
				k->finish->ant_num++;
				ft_printf("L%d-%s ", cur->ant_num, k->finish->name);
			}
			cur->ant_num = 0;
		}
		cur->ant_num = inc_ant;
		if (cur->ant_num > 0)
			ft_printf("L%d-%s ", inc_ant, cur->name);
	}
	else
	{
		ant_move2(k, tmp, i);
		cur->ant_num > 0 ? ft_printf("L%d-%s ", cur->ant_num, cur->name) : 0;
		ant_move(k, tmp, inc_ant, i - 1);
	}
}

void		ant_move2(t_room_keeper *k, t_room_links *tmp, int i)
{
	t_room *prev;
	t_room *cur;

	cur = k->n[tmp->data->rooms[i]];
	if (i == tmp->data->length - 2)
	{
		if (cur->ant_num > 0)
		{
			tmp->data->ants_counter--;
			k->finish->ant_num++;
			ft_printf("L%d-%s ", cur->ant_num, k->finish->name);
		}
		cur->ant_num = 0;
	}
	if (i > 1)
	{
		prev = k->n[tmp->data->rooms[i - 1]];
		if (prev->ant_num != 0)
		{
			cur->ant_num = prev->ant_num;
			prev->ant_num = 0;
		}
	}
}

void		check_oper(t_room_links *start, int *oper, int f)
{
	if (oper[0] > start->data->ants_counter + start->data->length - 2)
	{
		oper[0] = start->data->ants_counter + start->data->length - 2;
		oper[1] = f;
	}
}

int			*prepare_ants(t_room_keeper *k, t_map_keeper *mp, int f, int *oper)
{
	t_room_links	*start;
	t_room_links	*tmp;
	int				ant_num;
	int				ants;

	ants = k->ants;
	ant_num = 0;
	start = mp->rl;
	if (start == NULL)
		return (oper);
	while (start->data->field < f)
		start = start->next;
	while (ants--)
	{
		tmp = start;
		while (tmp->next != NULL && tmp->data->length +
			tmp->data->ants_counter >= tmp->next->data->length +
			tmp->next->data->ants_counter && tmp->next->data->field == f)
			tmp = tmp->next;
		in_queue(tmp->data->queue, ++ant_num);
		tmp->data->ants_counter++;
	}
	check_oper(start, oper, f);
	return (oper);
}

void		move_ants(t_room_keeper *keeper, t_map_keeper *mp, int field)
{
	int				operation_count;
	t_room_links	*start;
	t_room_links	*tmp;

	operation_count = 0;
	start = mp->rl;
	while (start->data->field < field)
		start = start->next;
	if (keeper->bon->chains)
		print_chains(keeper, start);
	while (keeper->finish->ant_num != keeper->ants)
	{
		tmp = start;
		while (tmp != NULL && tmp->data->field == field)
		{
			if (tmp->data->ants_counter > 0)
				ant_move(keeper, tmp, out_queue(tmp->data->queue),
											tmp->data->length - 2);
			tmp = tmp->next;
		}
		ft_printf("\n");
		operation_count++;
	}
	if (keeper->bon->numbers == 1)
		ft_printf("\nNumber of lines: %d\n", operation_count);
}
