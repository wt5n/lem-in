#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "libft/libft.h"

typedef struct				s_list_queue
{
   int						id;
   struct s_list_queue		*next;
}							t_list_queue;

typedef	struct 		s_map_keeper
{
	struct s_map	*next;
	int				field;
}					t_map_keeper;


typedef		struct	s_map
{
	int				length;
	int				field;
	int				*rooms;
}					t_map;

typedef 	struct	s_link
{
	char 			*name;
	struct 	s_link  *next;
	int				used;
}					t_link;

typedef struct      s_queue
{
   t_list_queue    *stack;
}                   t_queue;

typedef struct		s_room
{
	int				CheckAnt;
	char			*name;
	int				id;
	// struct	s_link 	*links;
	int				*links_id;
	int				*links_used;
	int				links_count;
	// struct s_room	*next ;
	int				visited;
	int				prev_room;
}					t_room;

typedef struct 	s_room_keeper
{
	int 		RoomCounter; // a on nuzen?
	t_room 		**n;
	// t_room		*start;
	// t_room		*finish;
}				t_room_keeper;

typedef struct  s_validation
{
	int         room_nums;
	int         start_com;
	int         end_com;
	int         ants;
	t_room      **n;
	t_room      *start;
	t_room      *finish;
}               t_validation;


void    in_queue(t_queue *q, int x);
int		out_queue(t_queue *q);
// int		get_hash(char *name);
t_room	*create_room(char *name, int id);
void	add_next(t_room *master, t_room *slave);
void	print_all_links(char *name, t_link *links);
void    add_links(t_room *room, int link);
void	add_two_links(t_room *first, t_room *second);
int 	add_links_to_queue(int id, t_queue *queue, t_room_keeper *keeper);
int		path_to_finish(t_room_keeper *keeper, t_map_keeper *mp);
void	add_prev_room(t_room *room, int prev);
void	main_loop(t_room_keeper *keeper, t_map_keeper *mp);
void    add_room(t_validation *validation, t_room *room);
void    start_end_rooms(t_validation *validation, t_room *room);
void    init_room_keeper(t_validation **validation);
void    parse_ants(t_validation *validation, char *line);
void    parse_comms(t_validation *validation, char *line);
void    parse_rooms(t_validation *validation, char* line);
void    parse_links(t_validation *validation, char* line);
void    parser_input(t_validation *validation);

#endif
