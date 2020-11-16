/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:02:03 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/16 20:50:25 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_errors_lem_in(int error_num)
{
	if (error_num == 1)
		write(2, "Ants number not correct!\n", 25);
	else if (error_num == 2)
		write(2, "Start/end error\n", 16);
	else if (error_num == 3)
		write(2, "Links error\n", 12);
	else if (error_num == 4)
		write(2, "Using L or # in the room name\n", 30);
	else if (error_num == 5)
		write(2, "No rooms\n", 9);
	else if (error_num == 6)
		write(2, "Comment error\n", 14);
	else if (error_num == 7)
		write(2, "Something wrong with rooms\n", 27);
	else if (error_num == 8)
		write(2, "Coordinate problem\n", 19);
	else if (error_num == 9)
		write(2, "No map\n", 7);
	else
		write(2, "Unknown error\n", 14);
	exit(2);
}

void	pass_to_n(t_room_keeper *keeper)
{
	int i;

	i = -1;
	while (++i < HASH_ROOMS)
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

void	start_end_rooms(t_room_keeper *keeper, t_room *room)
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
	t_room			*tmp1;
	t_room			*tmp2;
	unsigned long	i;
	unsigned long	j;
	int				num;

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

void	check_dup_coor(t_room_keeper *keeper, t_room *room, const int *xy)
{
	int		i;
	int 	j;

	i = 1;
	j = 1;
	if (xy[0] < 0 || xy[1] < 0)
		ft_errors_lem_in(8);
	while (j < HASH_ROOMS && keeper->coords[0][j] != xy[0])
		j++;
	while (i < HASH_ROOMS && keeper->coords[1][i] != xy[1] && keeper->coords[0][j - 1] == xy[0])
		i++;
	if (i == j && room->id != i)
		ft_errors_lem_in(8);
	else
	{
		keeper->coords[0][room->id] = xy[0];
		keeper->coords[1][room->id] = xy[1];
	}
}