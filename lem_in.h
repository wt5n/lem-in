#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "libft/libft.h"

#define VALUE_HASH_ROOMS 10000
#define NUM_LINKS 10

typedef struct				s_list_queue
{
   int						id;
   struct s_list_queue		*next;
}							t_list_queue;

typedef struct      s_queue
{
	t_list_queue    *stack;
}                   t_queue;

typedef		struct	s_map
{
    int				length;
    int				field;
    int             ants_counter;
    int				*rooms;
    t_queue         *queue;
}					t_map;

typedef	struct		s_room_links
{
	t_map				*data;
	struct s_room_links	*next;
}					t_room_links;

typedef	struct 		s_map_keeper
{
	t_room_links	*rl;
	int				field;
}					t_map_keeper;

// typedef 	struct	s_link
// {
// 	char 			*name;
// 	struct 	s_link  *next;
// 	int				used;
// }					t_link;

typedef struct		s_room
{
	char			*name;
	int				id;
	int             ant_num;
	int				**links_id;
	int				links_count;
	int				visited;
	int				prev_room;
	int				in_q;
	struct s_room	*next;
}					t_room;

typedef struct 	s_room_keeper
{
	int 		roomCounter;
	t_room 		**n;
	t_room      **n_hash;
	int         ants;
	int         s_c;
	int         e_c;
	t_room		*start;
	t_room		*finish;
	int			s_links;
	int			f_links;
	int			v_limit;
}				t_room_keeper;


void    in_queue(t_queue *q, int x);
int		out_queue(t_queue *q);
unsigned long     get_hash(unsigned char *name);
t_room	*create_room(char *name, int id);
void	add_next(t_room *master, t_room *slave);
//void	print_all_links(char *name, t_link *links);
void    add_links(t_room *room, int link);
void	add_two_links(t_room *first, t_room *second);
int 	add_links_to_queue(int id, t_queue *queue, t_room_keeper *keeper);
int		path_to_finish(t_room_keeper *keeper, t_map_keeper *mp);
void	master_loop(t_room_keeper *keeper, t_map_keeper *mp);
void    add_room(t_room_keeper *keeper, t_room *room);
void    start_end_rooms(t_room_keeper *keeper, t_room *room);
void    parse_ants(t_room_keeper *keeper, char *line);
void    parse_comms(t_room_keeper *keeper, char *line);
void    parse_rooms(t_room_keeper *keeper, char* line);
void    parse_links(t_room_keeper *keeper, char* line);
void    parse_input(t_room_keeper *keeper);
void    pass_to_n(t_room_keeper *keeper);
t_map    *create_map(int length, int field);
void    add_map_to_map_keeper(t_room_links *rl, t_map *map);
void    clear_rooms(t_room_keeper *keeper);
int     delete_collisions(t_room_keeper *keeper);
void    print_maps(t_map_keeper *mp);
void    print_links(t_room_keeper *keeper, int id);
int     find_room(t_room_keeper *keeper, int r, int find);
void	find_links_name(t_room **n_hash, char *room1, char *room2);
void    ant_move(t_room_keeper *keeper, t_room_links *tmp, int inc_ant, int i);
int *prepare_ants(t_room_keeper *keeper, t_map_keeper *mp, int field, int *oper);
void move_ants(t_room_keeper *keeper, t_map_keeper *mp, int field);
void	free_all(t_room_keeper * keeper, t_map_keeper *mp);
//void	free_list_queue(t_list_queue *queue);
void 	free_queue(t_queue *queue);
void    ft_errors_lem_in(int error_num);

#endif
