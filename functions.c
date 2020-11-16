/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:29:51 by ksenaida          #+#    #+#             */
/*   Updated: 2020/11/16 19:30:28 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

unsigned long	get_hash(unsigned char *name)
{
	unsigned long hash;
	int c;

	hash = HASH_ROOMS;
	while ((c = *name++))
		hash = ((hash << 5) + hash) + c;
	return (hash % HASH_ROOMS);
}
