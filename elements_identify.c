/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_identify.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:47:46 by crepou            #+#    #+#             */
/*   Updated: 2023/03/26 18:49:05 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coordinates	*elem_identify(t_map *map, int x, int y)
{
	t_lines_table	*line;
	t_coordinates	**elem;
	int				i;

	line = map->lines_table;
	i = 0;
	while (i < y)
	{
		line = line->next;
		i++;
	}
	elem = line->points;
	return (elem[x]);
}
