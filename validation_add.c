#include "lem_in.h"

void    pass_to_n(t_room_keeper *keeper)
{
    int i = -1;
    while (++i < VALUE_HASH_ROOMS)
    {
        while (keeper->n_hash[i] != NULL)
        {
            keeper->n[keeper->n_hash[i]->id] = keeper->n_hash[i];
            if (keeper->n_hash[i]->next != NULL)
                keeper->n_hash[i] = keeper->n_hash[i]->next;
            else
                break ;
        }
    }
}

void    start_end_rooms(t_room_keeper *keeper, t_room *room)
{
    if (keeper->s_c == 1)
    {
        keeper->start = room;
        keeper->s_c++;
    }
    if (keeper->e_c == 1)
    {
        keeper->finish = room;
        keeper->e_c++;
    }
}

void	find_links_name(t_room **n_hash, char *room1, char *room2)
{
    t_room *tmp1;
    t_room *tmp2;
    unsigned long i;
    unsigned long j;
    int num;

    num = -1;
    i = get_hash(room1);
    j = get_hash(room2);
    tmp1 = n_hash[i];
    tmp2 = n_hash[j];
    if (tmp1 == NULL || tmp2 == NULL)
        ft_errors_lem_in(3);
    while (ft_strcmp(tmp1->name, room1) != 0)
        tmp1 = tmp1->next;
    while (ft_strcmp(tmp2->name, room2) != 0)
        tmp2 = tmp2->next;
    while (++num < tmp1->links_count)
        if (tmp1->links_id[0][num] == tmp2->id)
            ft_errors_lem_in(3);
    add_two_links(tmp1, tmp2);
}
