#include "lem_in.h"

void    add_room(t_room_keeper *keeper, t_room *room)
{
	if (keeper->n_hash[get_hash(room->name)])
	{
		add_next(keeper->n_hash[get_hash(room->name)], room);
	}
	else
		keeper->n_hash[get_hash(room->name)] = room;
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

void    parse_ants(t_room_keeper *keeper, char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if (keeper->ants)
			break ;
		if (*line && (*line == ' '))
			ft_error();
		if (*line && (*line == '-'))
			ft_error();
		while (*(line + i) && *(line + i) == '+' || ft_isdigit(*(line + i)))
			i++;
		keeper->ants = ft_atoi_wr(line);
		if (keeper->ants <= 0 || line[i] != '\0')
			ft_error();
	}
}

void    parse_comms(t_room_keeper *keeper, char *line)
{
	int i;

	i = 0;
	if (ft_strcmp(line, "##start") == 0)
		keeper->s_c++;
	else if (ft_strcmp(line, "##end") == 0)
		keeper->e_c++;
	else if (line[i] == '#' && (keeper->s_c || keeper->e_c)
	         && (ft_strcmp(line, "##start") != 0)
	         && (ft_strcmp(line, "##end") != 0))
		ft_error();
	else if (line[i] == '#' && (ft_strcmp(line, "##start") != 0
	                            && (ft_strcmp(line, "##end") != 0)))
		;
}

void    parse_rooms(t_room_keeper *keeper, char* line)
{
	char    *name;
	char    *str;
	char    *start;
	t_room  *room;

	str = line;
	start = str;
	name = NULL;
	(str[0] == 'L' || str[0] == '#') ? ft_error() : 0;
	while (*str != '\0')
		str++;
	str--;
	while (ft_isdigit(*str))
		str--;
	str--;
	while (ft_isdigit(*str))
		str--;
	name = ft_strndup(start, str - start);
	ft_strchr(name, ' ') ? ft_error() : 0;
	if (keeper->s_c == 1)
		room = create_room(name, 1);
	else if (keeper->e_c == 1)
		room = create_room(name, 2);
	else
	{
		keeper->RoomCounter++;
		room = create_room (name, keeper->RoomCounter - 1);
	}
	add_room(keeper, room);

	if (keeper->s_c == 1 || keeper->e_c == 1)
		start_end_rooms(keeper, room);
	keeper->s_c > 2 || keeper->e_c > 2 ? ft_error() : 0;
}

void    parse_links(t_room_keeper *keeper, char* line)
{
	char    *str;
	char    *minus;
	char    *room1;
	char    *room2;

	keeper->RoomCounter == 0 ? ft_error() : 0;
	(!keeper->start || !keeper->finish) ? ft_error() : 0;
	(keeper->start == keeper->finish) ? ft_error() : 0;
	str = line;
	minus = ft_strchr(str, '-');
	room1 = ft_strndup(str, minus - str);
	room2 = ft_strdup(minus + 1);
	add_two_links(keeper->n_hash[get_hash(room1)], keeper->n_hash[get_hash(room2)]);
	if (ft_strcmp(room1, room2) == 0)
		ft_error();
}

void    parse_input(t_room_keeper *keeper)
{
	char *line;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		if ((ft_isdigit(line[0]) || ft_isdigit(line[1])) && !keeper->ants)
			parse_ants(keeper, line);
		else if (line[0] == '#')
			parse_comms(keeper, line);
		else if (ft_strchr(line, ' ') && !(ft_strchr(line, '-'))
		         && !(ft_strchr(line, '#')))
			parse_rooms(keeper, line);
		else if (ft_strchr(line, '-'))
			parse_links(keeper, line);
		else
			ft_error();
		free(line);
	}
}