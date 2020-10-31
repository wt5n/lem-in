#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "libft/libft.h"

typedef	struct 	s_map_keeper
{

};


typedef		struct	s_map
{
	int				length;
	int				field;
	char			**rooms;
	// struct 	s_maps	*next;
}					t_map;

typedef 	struct	s_link
{
	char 			*name;
	struct 	s_link  *next;
	int				used;
}					t_link;

typedef struct      s_queue
{
	t_link          *stack;
}                   t_queue;

typedef struct		s_room
{
	int				CheckAnt;
	char			*name;
	int				hash;
	char          	**links;
	int				links_len;
	struct s_room	*next ;
	int				visited;
	// int				wave;
	// int				prev;
	// int				in_completed;
	// int				forward;
	// int				back;
	char			*tmp_prev_room;
	char			*prev_room;
}					t_room;

typedef struct 	s_room_keeper
{
	int 		RoomCounter;
	t_room 		**n;
	t_room		*start;
	t_room		*finish;
}				t_room_keeper;

void    in_queue(t_queue *q, char *x);
char     *out_queue(t_queue *q);

int		get_hash(char *name);
t_room	*create_room(char *name);
void	add_next(t_room *master, t_room *slave);
void	print_all_links(t_room *room);
void    increase_links(t_room *room);
void    add_links(t_room *room, char *link);
void	add_two_links(t_room *first, t_room *second);
int		add_links_to_queue(t_room *room, t_queue *queue, t_room_keeper *keeper);
t_queue *min_path_func(t_room_keeper *keeper);
void 	final_countdown(t_room_keeper *keeper, char* name, t_queue *queue);
int		path_to_finish(t_queue *queue, t_room_keeper *keeper);
void	add_tmp_prev_room(t_room *room, char **prev);
void	add_prev_room(t_room *room, char **prev);


#endif
