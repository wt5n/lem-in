/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:15:02 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/15 20:25:44 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

unsigned long	get_hash(unsigned char *name)
{
    unsigned long hash = HASH_ROOMS;
    int c;

    while ((c = *name++))
        hash = ((hash << 5) + hash) + c;

    return (hash % HASH_ROOMS);
}

void			find_count_s_f(t_room_keeper *keeper)
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

void			master_loop(t_room_keeper *keeper, t_map_keeper *mp)
{
    int i;
    int k;
    int *best_field;
    int min;
    int iii;

    iii = 0;
    if (!(best_field = (int *)ft_memalloc(sizeof(int) * 3)))
        return ;
    best_field[0] = MAXINT;
    best_field[1] = 0;
    i = 1;
    k = 0;
    min = min_n(keeper->s_links, keeper->f_links);
    keeper->n[1]->visd = 1000000;
    if (find_room(keeper, 1, 2) >= 0)
    {
        while (++iii < keeper->ants + 1)
            ft_printf("L%d-%s ", iii ,keeper->finish->name);
        exit(1);
    }
    while (1)
    {
        while (i != 0)
        {
            i = path_to_finish(keeper, mp);
            k += i;
            if (min == k)
                break;
            keeper->v_limit++;
        }
        best_field = prepare_ants(keeper, mp, mp->field, best_field);
        if (min == k || delete_collisions(keeper) == 0 || mp->field == 5)
            break;
        clear_rooms(keeper);
        keeper->n[1]->visd = 1000000;
        keeper->v_limit = 1;
        mp->field++;
        k = 0;
        i = 1;
    }
    move_ants(keeper, mp, best_field[1]);
    free(best_field);
}

int			main(void)
{
	t_room_keeper	*r;
	t_map_keeper	*mp;

	if (!(r = (t_room_keeper*)ft_memalloc(sizeof(t_room_keeper))))
		return (0);
	if (!(r->n_hash = (t_room**)ft_memalloc(sizeof(t_room*) * HASH_ROOMS)))
		return (0);
	r->roomCounter = 3;
	parse_input(r);
	if (!(r->n = (t_room**)ft_memalloc(sizeof(t_room*) * r->roomCounter)))
		return (0);
	r->v_limit = 1;
	pass_to_n(r);
	if (!(mp = (t_map_keeper*)ft_memalloc(sizeof(t_map_keeper))))
		return (0);
	mp->field = 1;
	if (!(mp->rl = (t_room_links*)ft_memalloc(sizeof(t_room_links))))
		return (0);
	find_count_s_f(r);
	r->start->ant_num = r->ants;
	master_loop(r, mp);
	free_all(r, mp);
	return (1);
}
