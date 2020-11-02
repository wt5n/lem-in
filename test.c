#include "lem_in.h"

int main (void)
{
	t_validation *validation;
	init_room_keeper(&validation);
	validation->n = (t_room**)ft_memalloc(sizeof(t_room*) * 3000);
	parser_input(validation);
	int hash = get_hash("room3");
	printf("%s\n", validation->n[hash]->name);
	printf("%s\n", validation->n[hash]->links->name);
	return 0;
} 