/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:42:46 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/16 21:04:00 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

void	show_help(void)
{
	ft_printf("Usage example:\n");
	ft_printf("	./lem-in < name_of_map\n");
	ft_printf("Flags:\n");
	ft_printf("-n. Show number of lines\n");
	ft_printf("-c. Show chaines\n");
	ft_printf("Obrabotka oshibok (bez flafa)\n");
	ft_printf("--about. Description of project\n");
	ft_printf("--credits. Information about project creators\n");
}

void	about(void)
{
	ft_putstr("Lem in project. The goal of project is to find the quicest");
	ft_putstr(" way to get N antc across the farm.\n");
	ft_putstr("Program receive the data describing the ant farm from thr");
	ft_putstr(" standart output in the following format:\n");
	ft_putstr("		number_of_ants\n");
	ft_putstr("		the_rooms\n");
	ft_putstr("		the_links\n");
	ft_putstr("Quickest wat means the solution with least number of lines\n\n");
	ft_putstr("Rules of the game:\n");
	ft_putstr(" - At the beggining all the ants in the room ##start. The goal");
	ft_putstr(" is bring them to the room ##finish with as few turns as");
	ft_putstr(" possible.\n");
	ft_putstr(" - Each room can containt only one ant at a time, except rooms");
	ft_putstr(" ##start and ##end.\n");
	ft_putstr(" - All ant itn thr ##start room at the beggining of the game\n");
	ft_putstr(" - Moved ants must be displayed every turn, ony moved\n");
	ft_putstr(" - At each turn you can move each ant only once throught a");
	ft_putstr(" tube (the room at receiving end mst be empy)\n");
}

void	credits(void)
{
	ft_printf("The project 'Why doth weary prostitution scour not Cupid’s");
	ft_printf(" emancipation? O capital insolence!' was createb by\n");
	ft_printf("Ksenaida and Hlikely\n");
}