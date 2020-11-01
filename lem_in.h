#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "libft/libft.h"

typedef struct				s_list_queue
{
   char						*content;
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
	char			**rooms;
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
	int				hash;
	struct	s_link 	*links;
	int				num_of_links;
	struct s_room	*next ;
	int				visited;
	char			*prev_room;
}					t_room;

typedef struct 	s_room_keeper
{
	int 		RoomCounter; // a on nuzen?
	t_room 		**n;
	t_room		*start;
	t_room		*finish;
}				t_room_keeper;

void    in_queue(t_queue *q, char *x);
char	*out_queue(t_queue *q);
int		get_hash(char *name);
t_room	*create_room(char *name);
void	add_next(t_room *master, t_room *slave);
void	print_all_links(t_room *room);
void    add_links(t_room *room, char *link);
void	add_two_links(t_room *first, t_room *second);
int 	add_links_to_queue(t_room *room, t_queue *queue, t_room_keeper *c_k2);
int		path_to_finish(t_room_keeper *c_k1, t_map_keeper *mp);
void	add_prev_room(t_room *room, char *prev);
void	main_loop(t_room_keeper *keeper, t_map_keeper *mp);

#endif
