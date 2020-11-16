/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:42:46 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/16 21:23:31 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

void	print_chains(t_room_keeper *keeper, t_room_links *s)
{
	t_room_links	*tmp;
	int				i;

	tmp = s;
	ft_printf("Chains of the chosen field\n");
	while (s != NULL)
	{
		i = -1;
		while (++i < s->data->length)
			ft_printf("%s ", keeper->n[s->data->rooms[i]]->name);
		s = s->next;
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	show_help(void)
{
	ft_printf("Usage example:\n");
	ft_printf("	./lem-in < name_of_map\n");
	ft_printf("Flags:\n");
	ft_printf("-n. Show number of lines\n");
	ft_printf("-c. Show chains\n");
	ft_printf("--about. Description of project\n");
	ft_printf("--credits. Information about project creators\n");
}

void	about(void)
{
	ft_putstr("Lem in project. The goal of project is to find the quickest");
	ft_putstr(" way to get N ants across the farm.\n");
	ft_putstr("Program receive the data describing the ant farm from thr");
	ft_putstr(" standard output in the following format:\n");
	ft_putstr("		number_of_ants\n");
	ft_putstr("		the_rooms\n");
	ft_putstr("		the_links\n");
	ft_putstr("Quickest wat means the solution with least number of lines\n\n");
	ft_putstr("Rules of the game:\n");
	ft_putstr(" - At the beginning all the ants in the room ##start. The goal");
	ft_putstr(" is bring them to the room ##finish with as few turns as");
	ft_putstr(" possible.\n");
	ft_putstr(" - Each room can contains only one ant at a time, except rooms");
	ft_putstr(" ##start and ##end.\n");
	ft_putstr(" - All ant itn thr ##start room at the beginning of the game\n");
	ft_putstr(" - Moved ants must be displayed every turn, ony moved\n");
	ft_putstr(" - At each turn you can move each ant only once through a");
	ft_putstr(" tube (the room at receiving end mst be empty)\n");
}

void	credits(void)
{
	ft_printf("The project 'Why doth weary prostitution scour not Cupid’s");
	ft_printf(" emancipation? O capital insolence!' was createb by\n");
	ft_printf("Ksenaida and Hlikely\n");
}