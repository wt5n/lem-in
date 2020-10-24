#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "libft/libft.h"

typedef struct		s_link
{
	char 			*name;
	struct s_list	*next;
}					t_link;

typedef struct      s_queue
{
	t_link          *stack1;
}                   t_queue;

typedef struct		s_room
{
	int				CheckAnt;
	char			*name_room;
	int				hash;
	char          	**links;
	int				links_len;
	struct s_room	*next ;
}					t_room;

typedef struct s_room_keeper
{
	int RoomCounter;
	t_room **n;
}				t_room_keeper;

void    in_queue(t_queue *q, char *x);
char     *out_queue(t_queue *q);

int		get_hash(char *name);
t_room	*create_room(char *name);
void	add_next(t_room *master, t_room *slave);
void	print_all_links(t_room *room);
void    increase_links(t_room *room);
void    add_links(t_room *room, char *link);

#endif
