/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:30:16 by crepou            #+#    #+#             */
/*   Updated: 2023/04/09 21:43:12 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char ***map, int x, int y, t_map *mp)
{
	if ((*map)[x][y] == '1' || (*map)[x][y] == 'F')
		return ;
	(*map)[x][y] = 'F';
	flood_fill(map, x - 1, y, mp);
	flood_fill(map, x + 1, y, mp);
	flood_fill(map, x, y - 1, mp);
	flood_fill(map, x, y + 1, mp);
	return ;
}

char	**create_array_map(t_map *mp)
{
	char			**new_map;
	int				i;
	t_lines_table	*lines;
	int				j;

	new_map = (char **)malloc(sizeof(char *) * mp->map_info->co_y);
	i = 0;
	lines = mp->lines_table;
	while (i < mp->map_info->co_y)
	{
		new_map[i] = (char *)malloc(sizeof(char) * mp->map_info->co_x);
		j = 0;
		while (j < mp->map_info->co_x)
		{
			new_map[i][j] = lines->points[j]->val;
			j++;
		}
		lines = lines->next;
		i++;
	}
	return (new_map);
}

int	has_element(char **map, int x, int y, char type)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (map[i][j] == type)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_array_map(char ***map, t_map *mp)
{
	int	i;

	i = 0;
	while (i < mp->map_info->co_y)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}

int	all_are_reachable(t_map *mp, int x, int y)
{
	char	**map;

	map = create_array_map(mp);
	flood_fill(&map, x, y, mp);
	if (has_element(map, mp->map_info->co_x, mp->map_info->co_y, 'C') \
		|| has_element(map, mp->map_info->co_x, mp->map_info->co_y, 'E'))
	{
		free_array_map(&map, mp);
		return (0);
	}
	free_array_map(&map, mp);
	return (1);
}
