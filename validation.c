#include "lem_in.h"

void    start_end_rooms(t_validation *validation, t_room *room)
{
	if (validation->start_com == 1)
	{
		validation->start = room;
		validation->start_com++;
	}
	if (validation->end_com == 1)
	{
		validation->finish = room;
		validation->end_com++;
	}
}

void    add_room(t_validation *validation, t_room *room)
{
	if (validation->n[get_hash(room->name)])
	{
		add_next(validation->n[get_hash(room->name)], room);
	}
	else
		validation->n[get_hash(room->name)] = room;
}

void    init_room_keeper(t_validation **validation)
{
	if (!(*validation = (t_validation*)ft_memalloc(sizeof(t_validation))))
		exit(-1);
}

void    parse_ants(t_validation *validation, char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if (validation->ants)
			break ;
		if (*line && (*line == ' '))
			ft_error();
		if (*line && (*line == '-'))
			ft_error();
		while (*(line + i) && *(line + i) == '+' || ft_isdigit(*(line + i)))
			i++;
		validation->ants = ft_atoi_wr(line);
		if (validation->ants <= 0 || line[i] != '\0')
			ft_error();
	}
}

void    parse_comms(t_validation *validation, char *line)
{
	int i;

	i = 0;
	if (ft_strcmp(line, "##start") == 0)
		validation->start_com++;
	else if (ft_strcmp(line, "##end") == 0)
		validation->end_com++;
	else if (line[i] == '#' && (validation->start_com || validation->end_com)
	         && (ft_strcmp(line, "##start") != 0)
	         && (ft_strcmp(line, "##end") != 0))
		ft_error();
	else if (line[i] == '#' && (ft_strcmp(line, "##start") != 0
	                            && (ft_strcmp(line, "##end") != 0)))
		;
}

void    parse_rooms(t_validation *validation, char* line)
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
	room = create_room(name);
	add_room(validation, room);
	validation->room_nums++;
	if (validation->start_com == 1 || validation->end_com == 1)
		start_end_rooms(validation, room);
	validation->start_com > 2 || validation->end_com > 2 ? ft_error() : 0;
}

void    parse_links(t_validation *validation, char* line)
{
	char    *str;
	char    *minus;
	char    *room1;
	char    *room2;

	validation->room_nums == 0 ? ft_error() : 0;
	(!validation->start || !validation->finish) ? ft_error() : 0;
	(validation->start == validation->finish) ? ft_error() : 0;
	str = line;
	minus = ft_strchr(str, '-');
	room1 = ft_strndup(str, minus - str);
	room2 = ft_strdup(minus + 1);
	add_two_links(validation->n[get_hash(room1)], validation->n[get_hash(room2)]);
	if (ft_strcmp(room1, room2) == 0)
		ft_error();
}

void    parser_input(t_validation *validation)
{
	char *line;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		if ((ft_isdigit(line[0]) || ft_isdigit(line[1])) && !validation->ants)
			parse_ants(validation, line);
		else if (line[0] == '#')
			parse_comms(validation, line);
		else if (ft_strchr(line, ' ') && !(ft_strchr(line, '-'))
		         && !(ft_strchr(line, '#')))
			parse_rooms(validation, line);
		else if (ft_strchr(line, '-'))
			parse_links(validation, line);
		else
			ft_error();
		free(line);
	}
}