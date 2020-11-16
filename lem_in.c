/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:15:02 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/16 22:01:14 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		find_count_s_f(t_room_keeper *keeper)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < keeper->n[1]->links_count)
		if (keeper->n[1]->links_id[0][i] != 0)
			j++;
	keeper->s_links = j;
	j = 0;
	i = -1;
	while (++i < keeper->n[2]->links_count)
		if (keeper->n[2]->links_id[0][i] != 0)
			j++;
	keeper->f_links = j;
}

void		only_finish_room(t_room_keeper *keeper, t_map_keeper *mp)
{
	int	i;

	i = -1;
	if (find_room(keeper, 1, 2) >= 0)
	{
		while (++i < keeper->ants + 1)
			ft_printf("L%d-%s ", i, keeper->finish->name);
		free_all(keeper, mp);
		exit(1);
	}
}

void		circle(t_room_keeper *k, t_map_keeper *mp, int *bf, int min)
{
	int	i;
	int	j;

	while (1)
	{
		j = 0;
		i = 1;
		while (i != 0)
		{
			i = path_to_finish(k, mp);
			if (min == (j += i))
				break ;
			k->v_limit++;
		}
		if (j == 0 && mp->field == 1)
			ft_errors_lem_in(777);
		bf = prepare_ants(k, mp, mp->field, bf);
		if (min == j || delete_collisions(k) == 0 || mp->field == 5)
			break ;
		clear_rooms(k);
		k->n[1]->visd = 1000000;
		k->v_limit = 1;
		mp->field++;
	}
}

void		master_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
	int	*best_field;
	int	min;

	if (!(best_field = (int *)ft_memalloc(sizeof(int) * 2)))
		return ;
	best_field[0] = MAXINT;
	best_field[1] = 0;
	min = min_n(keeper->s_links, keeper->f_links);
	keeper->n[1]->visd = 1000000;
	only_finish_room(keeper, mp);
	circle(keeper, mp, best_field, min);
	print_file(keeper);
	move_ants(keeper, mp, best_field[1]);
	free(best_field);
}

int			lem_in(t_bonuses *bon)
{
	t_room_keeper	*k;
	t_map_keeper	*mp;

	if (!(k = (t_room_keeper*)ft_memalloc(sizeof(t_room_keeper))))
		return (0);
	create_keeper(k);
	parse_input(k);
	if (!(k->n = (t_room**)ft_memalloc(sizeof(t_room*) * k->room_counter)))
		return (0);
	k->bon = bon;
	k->v_limit = 1;
	pass_to_n(k);
	if (!(mp = (t_map_keeper*)ft_memalloc(sizeof(t_map_keeper))))
		return (0);
	mp->field = 1;
	if (!(mp->rl = (t_room_links*)ft_memalloc(sizeof(t_room_links))))
		return (0);
	find_count_s_f(k);
	k->start->ant_num = k->ants;
	master_loop(k, mp);
	free_all(k, mp);
	return (1);
}
