#include "lem_in.h"

void    ant_move(t_room_keeper *keeper, t_room_links *tmp, int inc_ant, int i)
{
    t_room  *cur;
    t_room  *prev;

    cur = keeper->n[tmp->data->rooms[i]];
    if (i == 1)
    {
        if (i == tmp->data->length - 2)
        {
            if (cur->ant_num > 0)
            {
                tmp->data->ants_counter--;
                keeper->finish->ant_num++;
                ft_printf("L%d-%s ", cur->ant_num, keeper->finish->name);
            }
            cur->ant_num = 0;
        }
        cur->ant_num = inc_ant;
        if (cur->ant_num > 0)
            ft_printf("L%d-%s ", inc_ant, cur->name);
    }
    else
    {
        if (i == tmp->data->length - 2)
        {
            if (cur->ant_num > 0)
            {
                tmp->data->ants_counter--;
                keeper->finish->ant_num++;
                ft_printf("L%d-%s ", cur->ant_num, keeper->finish->name);
            }
            cur->ant_num = 0;
        }
        if (i > 1)
        {
            prev = keeper->n[tmp->data->rooms[i - 1]];
            if (prev->ant_num != 0)
            {
                cur->ant_num = prev->ant_num;
                prev->ant_num = 0;
            }
        }
        if (cur->ant_num > 0)
            ft_printf("L%d-%s ", cur->ant_num, cur->name);
        ant_move(keeper, tmp, inc_ant, i - 1);
    }
}

int *prepare_ants(t_room_keeper *keeper, t_map_keeper *mp, int field, int *oper)
{
    t_room_links *start;
    t_room_links *tmp;
    int ant_num;
    int ants = keeper->ants;

    ant_num = 0;
    start = mp->rl;
    if (start == NULL)
        return oper;
    while (start->data->field < field)
        start = start->next;
    while (ants--)
    {
        tmp = start;
        ant_num++;
        while (tmp->next != NULL && tmp->data->length + tmp->data->ants_counter >=
                                    tmp->next->data->length + tmp->next->data->ants_counter
               && tmp->next->data->field == field)
            tmp = tmp->next;
        in_queue(tmp->data->queue, ant_num);
        tmp->data->ants_counter++;
    }
    if (oper[0] > start->data->ants_counter + start->data->length - 2)
    {
        oper[0] = start->data->ants_counter + start->data->length - 2;
        oper[1] = field;
    }
    return (oper);
}

void move_ants(t_room_keeper *keeper, t_map_keeper *mp, int field)
{
    int operation_count;
    t_room_links *start;
    t_room_links *tmp;

    operation_count = 0;
    start = mp->rl;
    while (start->data->field < field)
        start = start->next;
    while (keeper->finish->ant_num != keeper->ants)
    {
        tmp = start;
        while (tmp != NULL && tmp->data->field == field)
        {
            if (tmp->data->ants_counter > 0)
                ant_move(keeper, tmp, out_queue(tmp->data->queue), tmp->data->length - 2);
            tmp = tmp->next;
        }
        ft_printf("\n");
        operation_count++;
    }
    ft_printf("%d\n", operation_count);
}