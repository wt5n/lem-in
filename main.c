/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:39:44 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/17 16:05:07 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_flags(int argc, char **argv, t_bonuses *bon)
{
	int	i;

	i = 0;
	if (ft_strcmp(argv[1], "--help") == 0)
	{
		show_help();
		exit(1);
	}
	if (ft_strcmp(argv[1], "--about") == 0)
	{
		about();
		exit(1);
	}
	if (ft_strcmp(argv[1], "--credits") == 0)
	{
		credits();
		exit(1);
	}
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "-n") == 0)
			bon->numbers = 1;
		if (ft_strcmp(argv[i], "-c") == 0)
			bon->chains = 1;
	}
}

int		main(int argc, char **argv)
{
	t_bonuses *bon;

	bon = (t_bonuses*)ft_memalloc(sizeof(t_bonuses));
	if (argc > 1)
		find_flags(argc, argv, bon);
	lem_in(bon);
}
