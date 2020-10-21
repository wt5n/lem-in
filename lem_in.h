#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

typedef struct		s_link
{
	char 			*name;
	struct s_list	*next;
}					t_link;

typedef struct		s_room
{
	int				CheckAnt;
	char			*name_room;
	int				hash;
	t_link			links;
	struct room		*next ;
}					t_room;

typedef struct s_room_keeper
{
	int RoomCounter;
	t_room n[5000];
}				t_room_keeper;

#endif
