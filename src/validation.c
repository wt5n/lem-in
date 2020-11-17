/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:12:54 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/17 20:52:51 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		parse_ants(t_room_keeper *keeper, char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if (keeper->ants)
			break ;
		if (*line && (*line == ' '))
			ft_errors_lem_in(1);
		if (*line && (*line == '-'))
			ft_errors_lem_in(1);
		while ((*(line + i) && *(line + i) == '+') || ft_isdigit(*(line + i)))
			i++;
		keeper->ants = ft_atoi_wr(line);
		if (keeper->ants <= 0 || line[i] != '\0')
			ft_errors_lem_in(1);
	}
}

void		parse_comms(t_room_keeper *keeper, char *line)
{
	if ((keeper->s_c || keeper->e_c) && !keeper->ants)
		ft_errors_lem_in(6);
	if (ft_strcmp(line, "##start") == 0)
		keeper->s_c++;
	else if (ft_strcmp(line, "##end") == 0)
		keeper->e_c++;
	else if (line[0] == '#' && line[1] == '#' && (keeper->s_c || keeper->e_c)
				&& (ft_strcmp(line, "##start") != 0)
				&& (ft_strcmp(line, "##end") != 0))
		ft_errors_lem_in(6);
	else if (line[0] == '#' && (ft_strcmp(line, "##start") != 0
					&& (ft_strcmp(line, "##end") != 0)))
		;
}

void		parse_rooms(t_room_keeper *keeper, char *line)
{
	char	*name;
	char	*str;
	char	*start;
	t_room	*room;
	int		xy[2];

	str = line;
	start = str;
	name = NULL;
	room = NULL;
	(str[0] == 'L' || str[0] == '#') ? ft_errors_lem_in(4) : 0;
	ft_words(line) != 3 ? ft_errors_lem_in(34123) : 0;
	while (*str != '\0')
		str++;
	while (ft_isdigit(*(--str)))
		;
	xy[1] = ft_atoi_wr(str);
	while (ft_isdigit(*(--str)))
		;
	xy[0] = ft_atoi_wr(str);
	name = ft_strndup(start, str - start);
	valid_room(keeper, room, name, xy);
	keeper->s_c > 2 || keeper->e_c > 2 ? ft_errors_lem_in(2) : 0;
	free(name);
}

int			parse_links(t_room_keeper *keeper, char *line)
{
	char *str;
	char *minus;
	char *room1;
	char *room2;

	keeper->room_counter == 0 ? ft_errors_lem_in(5) : 0;
	(!keeper->start || !keeper->finish) ? ft_errors_lem_in(2) : 0;
	(keeper->start == keeper->finish) ? ft_errors_lem_in(2) : 0;
	str = line;
	minus = ft_strchr(str, '-');
	room1 = ft_strndup(str, minus - str);
	room2 = ft_strdup(minus + 1);
	find_links_name(keeper->n_hash, room1, room2);
	if (ft_strcmp(room1, room2) == 0)
		ft_errors_lem_in(3);
	free(room1);
	free(room2);
	return (1);
}

void		parse_input(t_room_keeper *keeper, int t)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		keeper->file[i] = ft_strdup(line);
		if (ft_strcmp(line, "") == 0)
			ft_errors_lem_in(135);
		if ((ft_isdigit(line[0]) || ft_isdigit(line[1])) && !keeper->ants)
			parse_ants(keeper, line);
		else if (line[0] == '#')
			parse_comms(keeper, line);
		else if (line[0] != ' ' && ft_strchr(line, ' ') && t != 1
			&& !(ft_strchr(line, '-')) && !(ft_strchr(line, '#')))
			parse_rooms(keeper, line);
		else if (ft_strchr(line, '-'))
			t = parse_links(keeper, line);
		else
			ft_errors_lem_in(0);
		free(line);
		i++;
	}
	ft_free_two_demention(keeper->names, HASH_ROOMS - 1);
}
